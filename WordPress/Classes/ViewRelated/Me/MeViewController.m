// Me contents:
//
// + (No Title)
// | Account Settings
// | Help & Support
//
// + (No Title)
// | Log out

#import "MeViewController.h"
#import "SettingsViewController.h"
#import "SupportViewController.h"
#import "UIImageView+AFNetworkingExtra.h"
#import "MeHeaderView.h"
#import "ContextManager.h"
#import "AccountService.h"
#import "WPAccount.h"

const typedef enum {
    MeRowAccountSettings = 0,
    MeRowHelp = 1,
    MeRowLogout = 0
} MeRow;

const typedef enum {
    MeSectionGeneralType = 0,
    MeSectionLogout
} MeSectionContentType;

static NSString *const MVCCellReuseIdentifier = @"MVCCellReuseIdentifier";

static NSString *const MVCAccountSettingsTitle = @"Account Settings";
static NSString *const MVCHelpTitle = @"Help & Support";
static NSString *const MVCLogoutTitle = @"Log out";

static CGFloat const MVCTableViewRowHeight = 50.0;

@interface MeViewController () <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) MeHeaderView *headerView;

@end

@implementation MeViewController

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)loadView
{
    [super loadView];

    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    self.tableView.rowHeight = MVCTableViewRowHeight;
    self.tableView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:MVCCellReuseIdentifier];
    [self.view addSubview:self.tableView];

    self.headerView = [[MeHeaderView alloc] initWithFrame:CGRectMake(0.0, 0.0, CGRectGetWidth(self.view.bounds), MeHeaderViewHeight)];
    self.tableView.tableHeaderView = self.headerView;

    [self setupAutolayoutConstraints];
}

- (void)setupAutolayoutConstraints
{
    NSMutableDictionary *views = [@{@"tableView": self.tableView} mutableCopy];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|[tableView]|"
                                                                      options:0
                                                                      metrics:nil
                                                                        views:views]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[tableView]|"
                                                                      options:0
                                                                      metrics:nil
                                                                        views:views]];
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(defaultAccountDidChange:) name:WPAccountDefaultWordPressComAccountChangedNotification object:nil];

    [self refreshDetails];
}

- (void)refreshDetails
{
    NSManagedObjectContext *context = [[ContextManager sharedInstance] mainContext];
    AccountService *accountService = [[AccountService alloc] initWithManagedObjectContext:context];
    WPAccount *defaultAccount = [accountService defaultWordPressComAccount];

    [self.headerView setUsername:defaultAccount.username];
    [self.headerView setGravatarEmail:@"oguz.kocer@automattic.com"];
}

#pragma mark - UITableViewDataSource methods

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if (section == MeSectionGeneralType) {
        return 2;
    }
    if (section == MeSectionLogout) {
        return 1;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MVCCellReuseIdentifier];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    [WPStyleGuide configureTableViewActionCell:cell];

    NSString *text = nil;
    if (indexPath.section == MeSectionGeneralType) {
        switch (indexPath.row) {
            case MeRowAccountSettings:
                text = MVCAccountSettingsTitle;
                break;
            case MeRowHelp:
                text = MVCHelpTitle;
                break;
            default:
                break;
        }
    }
    else if (indexPath.section == MeSectionLogout) {
        if (indexPath.row == MeRowLogout) {
            text = MVCLogoutTitle;
        }
    }
    cell.textLabel.text = NSLocalizedString(text, nil);
    return cell;
}

#pragma mark - UITableViewDelegate methods

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];

    if (indexPath.section == MeSectionGeneralType) {
        switch (indexPath.row) {
            case MeRowAccountSettings:
                [self navigateToSettings];
                break;
            case MeRowHelp:
                [self navigateToHelp];
                break;
            default:
                break;
        }
    }
    else if (indexPath.section == MeSectionLogout) {
        if (indexPath.row == MeRowLogout) {
            // log out
        }
    }
}

#pragma mark - Actions

- (void)navigateToSettings
{
    [WPAnalytics track:WPAnalyticsStatOpenedSettings];

    SettingsViewController *settingsViewController = [[SettingsViewController alloc] initWithStyle:UITableViewStyleGrouped];
    [self.navigationController pushViewController:settingsViewController animated:YES];
}

- (void)navigateToHelp
{
    SupportViewController *supportViewController = [[SupportViewController alloc] init];
    [self.navigationController pushViewController:supportViewController animated:YES];
}

#pragma mark - Notifications

- (void)defaultAccountDidChange:(NSNotification *)notification
{
    [self refreshDetails];
}

@end
