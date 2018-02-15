#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, WPAnalyticsStat) {
    WPAnalyticsStatNoStat, // Since we can't have a nil enum we'll use this to act as the nil
    WPAnalyticsStatABTestStart,
    WPAnalyticsStatAddedSelfHostedSite,
    WPAnalyticsStatAddedSelfHostedSiteButJetpackNotConnectedToWPCom,
    WPAnalyticsStatAppInstalled,
    WPAnalyticsStatAppReviewsCanceledFeedbackScreen,
    WPAnalyticsStatAppReviewsDeclinedToRateApp,
    WPAnalyticsStatAppReviewsDidntLikeApp,
    WPAnalyticsStatAppReviewsLikedApp,
    WPAnalyticsStatAppReviewsOpenedFeedbackScreen,
    WPAnalyticsStatAppReviewsRatedApp,
    WPAnalyticsStatAppReviewsSawPrompt,
    WPAnalyticsStatAppReviewsSentFeedback,
    WPAnalyticsStatAppSettingsImageOptimizationChanged,
    WPAnalyticsStatAppSettingsMediaRemoveLocationChanged,
    WPAnalyticsStatAppSettingsVideoOptimizationChanged,
    WPAnalyticsStatAppUpgraded,
    WPAnalyticsStatApplicationClosed,
    WPAnalyticsStatApplicationOpened,
    WPAnalyticsStatCreatedAccount,
    WPAnalyticsStatCreatedSite,
    WPAnalyticsStatCreateAccountInitiated,
    WPAnalyticsStatCreateAccountEmailExists,
    WPAnalyticsStatCreateAccountUsernameExists,
    WPAnalyticsStatCreateAccountFailed,
    WPAnalyticsStatCreateSiteValidationFailed,
    WPAnalyticsStatCreateSiteCreationFailed,
    WPAnalyticsStatCreateSiteSetTaglineFailed,
    WPAnalyticsStatCreateSiteSetThemeFailed,
    WPAnalyticsStatDefaultAccountChanged,
    WPAnalyticsStatEditorAddedPhotoViaLocalLibrary,
    WPAnalyticsStatEditorAddedVideoViaLocalLibrary,
    WPAnalyticsStatEditorAddedPhotoViaWPMediaLibrary,
    WPAnalyticsStatEditorAddedVideoViaWPMediaLibrary,
    WPAnalyticsStatEditorAddedOtherMediaViaWPMediaLibrary,
    WPAnalyticsStatEditorAddedPhotoViaOtherApps,
    WPAnalyticsStatEditorAddedVideoViaOtherApps,
    WPAnalyticsStatEditorAztecBetaLink,
    WPAnalyticsStatEditorAztecPromoLink,
    WPAnalyticsStatEditorAztecPromoPositive,
    WPAnalyticsStatEditorAztecPromoNegative,
    WPAnalyticsStatEditorClosed,
    WPAnalyticsStatEditorCreatedPost,
    WPAnalyticsStatEditorDiscardedChanges,
    WPAnalyticsStatEditorEditedImage,
    WPAnalyticsStatEditorEnabledNewVersion,
    WPAnalyticsStatEditorPublishedPost,
    WPAnalyticsStatEditorQuickPublishedPost,
    WPAnalyticsStatEditorQuickSavedDraft,
    WPAnalyticsStatEditorResizedPhoto,
    WPAnalyticsStatEditorResizedPhotoError,
    WPAnalyticsStatEditorSavedDraft,
    WPAnalyticsStatEditorScheduledPost,
    WPAnalyticsStatEditorTappedBlockquote,
    WPAnalyticsStatEditorTappedBold,
    WPAnalyticsStatEditorTappedHeader,
    WPAnalyticsStatEditorTappedHeaderSelection,
    WPAnalyticsStatEditorTappedHorizontalRule,
    WPAnalyticsStatEditorTappedHTML,
    WPAnalyticsStatEditorTappedImage,
    WPAnalyticsStatEditorMediaPickerTappedDismiss,
    WPAnalyticsStatEditorMediaPickerTappedDevicePhotos,
    WPAnalyticsStatEditorMediaPickerTappedCamera,
    WPAnalyticsStatEditorMediaPickerTappedMediaLibrary,
    WPAnalyticsStatEditorMediaPickerTappedOtherApps,
    WPAnalyticsStatEditorTappedItalic,
    WPAnalyticsStatEditorTappedLink,
    WPAnalyticsStatEditorTappedMore,
    WPAnalyticsStatEditorTappedMoreItems,
    WPAnalyticsStatEditorTappedOrderedList,
    WPAnalyticsStatEditorTappedStrikethrough,
    WPAnalyticsStatEditorTappedUnderline,
    WPAnalyticsStatEditorTappedUnlink,
    WPAnalyticsStatEditorTappedUnorderedList,
    WPAnalyticsStatEditorToggledOff,
    WPAnalyticsStatEditorToggledOn,
    WPAnalyticsStatEditorUpdatedPost,
    WPAnalyticsStatEditorUploadMediaFailed,
    WPAnalyticsStatEditorUploadMediaRetried,
    WPAnalyticsStatGravatarCropped,
    WPAnalyticsStatGravatarTapped,
    WPAnalyticsStatGravatarUploaded,
    WPAnalyticsStatInstallJetpackCanceled,
    WPAnalyticsStatInstallJetpackCompleted,
    WPAnalyticsStatLogSpecialCondition,
    WPAnalyticsStatLoginFailed,
    WPAnalyticsStatLoginFailedToGuessXMLRPC,
    WPAnalyticsStatLoginAutoFillCredentialsFilled,
    WPAnalyticsStatLoginAutoFillCredentialsUpdated,
    WPAnalyticsStatLoginEmailFormViewed,
    WPAnalyticsStatLoginEpilogueViewed,
    WPAnalyticsStatLoginForgotPasswordClicked,
    WPAnalyticsStatLoginMagicLinkOpenEmailClientViewed,
    WPAnalyticsStatLoginMagicLinkRequestFormViewed,
    WPAnalyticsStatLoginMagicLinkExited,
    WPAnalyticsStatLoginMagicLinkFailed,
    WPAnalyticsStatLoginMagicLinkOpened,
    WPAnalyticsStatLoginMagicLinkRequested,
    WPAnalyticsStatLoginMagicLinkSucceeded,
    WPAnalyticsStatLoginPasswordFormViewed,
    WPAnalyticsStatLoginProloguePaged,
    WPAnalyticsStatLoginPrologueViewed,
    WPAnalyticsStatLoginTwoFactorFormViewed,
    WPAnalyticsStatLoginURLFormViewed,
    WPAnalyticsStatLoginURLHelpScreenViewed,
    WPAnalyticsStatLoginUsernamePasswordFormViewed,
    WPAnalyticsStatLoginSocialButtonClick,
    WPAnalyticsStatLoginSocialButtonFailure,
    WPAnalyticsStatLoginSocialConnectSuccess,
    WPAnalyticsStatLoginSocialConnectFailure,
    WPAnalyticsStatLoginSocialSuccess,
    WPAnalyticsStatLoginSocialFailure,
    WPAnalyticsStatLoginSocial2faNeeded,
    WPAnalyticsStatLoginSocialAccountsNeedConnecting,
    WPAnalyticsStatLoginSocialErrorUnknownUser,
    WPAnalyticsStatLogout,
    WPAnalyticsStatLowMemoryWarning,
    WPAnalyticsStatMediaLibraryDeletedItems,
    WPAnalyticsStatMediaLibraryEditedItemMetadata,
    WPAnalyticsStatMediaLibraryPreviewedItem,
    WPAnalyticsStatMediaLibrarySharedItemLink,
    WPAnalyticsStatMediaLibraryAddedPhoto,
    WPAnalyticsStatMediaLibraryAddedVideo,
    WPAnalyticsStatMediaServiceUploadStarted,
    WPAnalyticsStatMediaServiceUploadFailed,
    WPAnalyticsStatMediaServiceUploadSuccessful,
    WPAnalyticsStatMediaServiceUploadCanceled,
    WPAnalyticsStatMenusAccessed,
    WPAnalyticsStatMenusCreatedItem,
    WPAnalyticsStatMenusCreatedMenu,
    WPAnalyticsStatMenusDeletedMenu,
    WPAnalyticsStatMenusDeletedItem,
    WPAnalyticsStatMenusDiscardedChanges,
    WPAnalyticsStatMenusEditedItem,
    WPAnalyticsStatMenusOpenedItemEditor,
    WPAnalyticsStatMenusOrderedItems,
    WPAnalyticsStatMenusSavedMenu,
    WPAnalyticsStatMeTabAccessed,
    WPAnalyticsStatMySitesTabAccessed,
    WPAnalyticsStatNotificationsCommentApproved,
    WPAnalyticsStatNotificationsCommentFlaggedAsSpam,
    WPAnalyticsStatNotificationsCommentLiked,
    WPAnalyticsStatNotificationsCommentRepliedTo,
    WPAnalyticsStatNotificationsCommentTrashed,
    WPAnalyticsStatNotificationsCommentUnapproved,
    WPAnalyticsStatNotificationsCommentUnliked,
    WPAnalyticsStatNotificationsMissingSyncWarning,
    WPAnalyticsStatNotificationsTappedNewPost,
    WPAnalyticsStatNotificationsTappedViewReader,
    WPAnalyticsStatNotificationsSettingsUpdated,
    WPAnalyticsStatNotificationsSiteFollowAction,
    WPAnalyticsStatNotificationsSiteUnfollowAction,
    WPAnalyticsStatNotificationsUploadMediaSuccessWritePost,
    WPAnalyticsStatNotificationsShareSuccessEditPost,
    WPAnalyticsStatOnePasswordFailed,
    WPAnalyticsStatOnePasswordLogin,
    WPAnalyticsStatOnePasswordSignup,
    WPAnalyticsStatOpenedAccountSettings,
    WPAnalyticsStatOpenedAppSettings,
    WPAnalyticsStatOpenedComments,
    WPAnalyticsStatOpenedLogin,
    WPAnalyticsStatOpenedMediaLibrary,
    WPAnalyticsStatOpenedMyProfile,
    WPAnalyticsStatOpenedNotificationsList,
    WPAnalyticsStatOpenedNotificationDetails,
    WPAnalyticsStatOpenedNotificationSettingsList,
    WPAnalyticsStatOpenedNotificationSettingStreams,
    WPAnalyticsStatOpenedNotificationSettingDetails,
    WPAnalyticsStatOpenedPages,
    WPAnalyticsStatOpenedPlans,
    WPAnalyticsStatOpenedPlansComparison,
    WPAnalyticsStatOpenedPeople,
    WPAnalyticsStatOpenedPerson,
    WPAnalyticsStatOpenedPlugins,
    WPAnalyticsStatOpenedPosts,
    WPAnalyticsStatOpenedSharingManagement,
    WPAnalyticsStatOpenedSiteSettings,
    WPAnalyticsStatOpenedSupport,
    WPAnalyticsStatOpenedViewAdmin,
    WPAnalyticsStatOpenedViewSite,
    WPAnalyticsStatPerformedCoreDataMigrationFixFor45,
    WPAnalyticsStatPerformedJetpackSignInFromStatsScreen,
    WPAnalyticsStatPerformedJetpackSignInFromNotificationsScreen,
    WPAnalyticsStatPersonUpdated,
    WPAnalyticsStatPersonRemoved,
    WPAnalyticsStatPluginUpdated,
    WPAnalyticsStatPluginRemoved,
    WPAnalyticsStatPostListAuthorFilterChanged,
    WPAnalyticsStatPostListDraftAction,
    WPAnalyticsStatPostListEditAction,
    WPAnalyticsStatPostListLoadedMore,
    WPAnalyticsStatPostListNoResultsButtonPressed,
    WPAnalyticsStatPostListOpenedCellMenu,
    WPAnalyticsStatPostListPublishAction,
    WPAnalyticsStatPostListScheduleAction,
    WPAnalyticsStatPostListPullToRefresh,
    WPAnalyticsStatPostListRestoreAction,
    WPAnalyticsStatPostListSearchOpened,
    WPAnalyticsStatPostListStatsAction,
    WPAnalyticsStatPostListStatusFilterChanged,
    WPAnalyticsStatPostListTrashAction,
    WPAnalyticsStatPostListViewAction,
    WPAnalyticsStatPushAuthenticationApproved,
    WPAnalyticsStatPushAuthenticationExpired,
    WPAnalyticsStatPushAuthenticationFailed,
    WPAnalyticsStatPushAuthenticationIgnored,
    WPAnalyticsStatPushNotificationAlertPressed,
    WPAnalyticsStatPushNotificationReceived,
    WPAnalyticsStatReaderAccessed,
    WPAnalyticsStatReaderArticleCommentedOn,
    WPAnalyticsStatReaderArticleLiked,
    WPAnalyticsStatReaderArticleOpened,
    WPAnalyticsStatReaderArticleReblogged,
    WPAnalyticsStatReaderArticleUnliked,
    WPAnalyticsStatReaderDiscoverViewed,
    WPAnalyticsStatReaderFreshlyPressedLoaded,
    WPAnalyticsStatReaderInfiniteScroll,
    WPAnalyticsStatReaderListFollowed,
    WPAnalyticsStatReaderListLoaded,
    WPAnalyticsStatReaderListPreviewed,
    WPAnalyticsStatReaderListUnfollowed,
    WPAnalyticsStatReaderSearchLoaded,
    WPAnalyticsStatReaderSearchPerformed,
    WPAnalyticsStatReaderSearchResultTapped,
    WPAnalyticsStatReaderSiteBlocked,
    WPAnalyticsStatReaderSiteFollowed,
    WPAnalyticsStatReaderSitePreviewed,
    WPAnalyticsStatReaderSiteUnfollowed,
    WPAnalyticsStatReaderTagFollowed,
    WPAnalyticsStatReaderTagLoaded,
    WPAnalyticsStatReaderTagPreviewed,
    WPAnalyticsStatReaderTagUnfollowed,
    WPAnalyticsStatSelectedInstallJetpack,
    WPAnalyticsStatSelectedLearnMoreInConnectToJetpackScreen,
    WPAnalyticsStatSentItemToGooglePlus,
    WPAnalyticsStatSentItemToInstapaper,
    WPAnalyticsStatSentItemToPocket,
    WPAnalyticsStatSentItemToWordPress,
    WPAnalyticsStatSharedItem,
    WPAnalyticsStatSharedItemViaEmail,
    WPAnalyticsStatSharedItemViaFacebook,
    WPAnalyticsStatSharedItemViaSMS,
    WPAnalyticsStatSharedItemViaTwitter,
    WPAnalyticsStatSharedItemViaWeibo,
    WPAnalyticsStatSharingButtonSettingsChanged,
    WPAnalyticsStatSharingButtonOrderChanged,
    WPAnalyticsStatSharingButtonShowReblogChanged,
    WPAnalyticsStatSharingOpenedPublicize,
    WPAnalyticsStatSharingOpenedSharingButtonSettings,
    WPAnalyticsStatSharingPublicizeConnected,
    WPAnalyticsStatSharingPublicizeDisconnected,
    WPAnalyticsStatSharingPublicizeConnectionAvailableToAllChanged,
    WPAnalyticsStatShortcutLogIn,
    WPAnalyticsStatShortcutNewPost,
    WPAnalyticsStatShortcutNewPhotoPost,
    WPAnalyticsStatShortcutStats,
    WPAnalyticsStatShortcutNotifications,
    WPAnalyticsStatSignedIn,
    WPAnalyticsStatSignedInToJetpack,
    WPAnalyticsStatSignupFailed,
    WPAnalyticsStatSignupMagicLinkFailed,
    WPAnalyticsStatSignupMagicLinkOpenEmailClientViewed,
    WPAnalyticsStatSignupMagicLinkRequested,
    WPAnalyticsStatSiteSettingsDeleteSiteAccessed,
    WPAnalyticsStatSiteSettingsDeleteSitePurchasesRequested,
    WPAnalyticsStatSiteSettingsDeleteSitePurchasesShowClicked,
    WPAnalyticsStatSiteSettingsDeleteSitePurchasesShown,
    WPAnalyticsStatSiteSettingsDeleteSiteRequested,
    WPAnalyticsStatSiteSettingsDeleteSiteResponseError,
    WPAnalyticsStatSiteSettingsDeleteSiteResponseOK,
    WPAnalyticsStatSiteSettingsExportSiteAccessed,
    WPAnalyticsStatSiteSettingsExportSiteRequested,
    WPAnalyticsStatSiteSettingsExportSiteResponseError,
    WPAnalyticsStatSiteSettingsExportSiteResponseOK,
    WPAnalyticsStatSiteSettingsStartOverAccessed,
    WPAnalyticsStatSiteSettingsStartOverContactSupportClicked,
    WPAnalyticsStatSkippedConnectingToJetpack,
    WPAnalyticsStatStatsAccessed,
    WPAnalyticsStatStatsInsightsAccessed,
    WPAnalyticsStatStatsPeriodDaysAccessed,
    WPAnalyticsStatStatsPeriodWeeksAccessed,
    WPAnalyticsStatStatsPeriodMonthsAccessed,
    WPAnalyticsStatStatsPeriodYearsAccessed,
    WPAnalyticsStatStatsScrolledToBottom,
    WPAnalyticsStatStatsSinglePostAccessed,
    WPAnalyticsStatStatsTappedBarChart,
    WPAnalyticsStatStatsViewAllAccessed,
    WPAnalyticsStatSupportOpenedHelpshiftScreen,
    WPAnalyticsStatSupportReceivedResponseFromSupport,
    WPAnalyticsStatSupportUserAcceptedTheSolution,
    WPAnalyticsStatSupportUserRejectedTheSolution,
    WPAnalyticsStatSupportUserSentScreenshot,
    WPAnalyticsStatSupportUserReviewedTheApp,
    WPAnalyticsStatSupportUserRepliedToHelpshift,
    WPAnalyticsStatThemesAccessedThemeBrowser,
    WPAnalyticsStatThemesAccessedSearch,
    WPAnalyticsStatThemesChangedTheme,
    WPAnalyticsStatThemesCustomizeAccessed,
    WPAnalyticsStatThemesDemoAccessed,
    WPAnalyticsStatThemesDetailsAccessed,
    WPAnalyticsStatThemesPreviewedSite,
    WPAnalyticsStatThemesSupportAccessed,
    WPAnalyticsStatTrainTracksRender,
    WPAnalyticsStatTrainTracksInteract,
    WPAnalyticsStatTwoFactorCodeRequested,
    WPAnalyticsStatTwoFactorSentSMS,
    WPAnalyticsStatShareExtensionError,
    WPAnalyticsStatMaxValue
};

extern NSString *const WPAnalyticsStatEditorPublishedPostPropertyCategory;
extern NSString *const WPAnalyticsStatEditorPublishedPostPropertyPhoto;
extern NSString *const WPAnalyticsStatEditorPublishedPostPropertyTag;
extern NSString *const WPAnalyticsStatEditorPublishedPostPropertyVideo;

@protocol WPAnalyticsTracker;
@interface WPAnalytics : NSObject

+ (void)registerTracker:(id<WPAnalyticsTracker>)tracker;
+ (void)clearTrackers;
+ (void)beginSession;
+ (void)refreshMetadata;
+ (void)beginTimerForStat:(WPAnalyticsStat)stat;
+ (void)endTimerForStat:(WPAnalyticsStat)stat withProperties:(NSDictionary *)properties;
+ (void)track:(WPAnalyticsStat)stat;
+ (void)track:(WPAnalyticsStat)stat withProperties:(NSDictionary *)properties;
+ (void)endSession;

@end

@protocol WPAnalyticsTracker <NSObject>

- (void)track:(WPAnalyticsStat)stat;
- (void)track:(WPAnalyticsStat)stat withProperties:(NSDictionary *)properties;

@optional
- (void)beginSession;
- (void)endSession;
- (void)refreshMetadata;
- (void)beginTimerForStat:(WPAnalyticsStat)stat;
- (void)endTimerForStat:(WPAnalyticsStat)stat withProperties:(NSDictionary *)properties;

@end
