import Gridicons
import WordPressFlux

@objc class CreateButtonCoordinator: NSObject {

    private enum Constants {
        static let padding: CGFloat = -16
        static let heightWidth: CGFloat = 56
        static let popoverOffset: CGFloat = -10
    }

    var button: FloatingActionButton = {
        let button = FloatingActionButton(image: .gridicon(.create))
        button.accessibilityLabel = NSLocalizedString("Create", comment: "Accessibility label for create floating action button")
        button.accessibilityIdentifier = "floatingCreateButton"
        button.accessibilityHint = NSLocalizedString("Creates new post or page", comment: " Accessibility hint for create floating action button")
        return button
    }()

    private weak var viewController: UIViewController?

    let newPost: () -> Void
    let newPage: () -> Void

    private let noticeAnimator = NoticeAnimator(duration: 0.5, springDampening: 0.7, springVelocity: 0.0)

    private lazy var notice: Notice = {
        let notice = Notice(title: NSLocalizedString("Create a post or page", comment: "The tooltip title for the Floating Create Button"),
                            message: "",
                            style: ToolTipNoticeStyle()) { _ in
        }
        return notice
    }()

    private var shouldShowNotice: Bool {
        set {
            //TODO: Set on persistent store
        }
        get {
            //TODO: Fetch from persistent store
            return true
        }
    }

    private weak var noticeContainerView: NoticeContainerView?

    @objc init(_ viewController: UIViewController, newPost: @escaping () -> Void, newPage: @escaping () -> Void) {
        self.viewController = viewController
        self.newPost = newPost
        self.newPage = newPage
    }

    /// Should be called any time the `viewController`'s trait collections will change. Dismisses when horizontal class changes to transition from .popover -> .custom
    /// - Parameter previousTraitCollection: The previous trait collection
    /// - Parameter newTraitCollection: The new trait collection
    @objc func presentingTraitCollectionWillChange(_ previousTraitCollection: UITraitCollection, newTraitCollection: UITraitCollection) {
        if let actionSheetController = viewController?.presentedViewController as? ActionSheetViewController {
            if previousTraitCollection.horizontalSizeClass != newTraitCollection.horizontalSizeClass {
                viewController?.dismiss(animated: false, completion: { [weak self] in
                    guard let self = self else {
                        return
                    }
                    self.setupPresentation(on: actionSheetController, for: newTraitCollection)
                    self.viewController?.present(actionSheetController, animated: false, completion: nil)
                })
            }
        }
    }

    @objc func add(to view: UIView, trailingAnchor: NSLayoutXAxisAnchor, bottomAnchor: NSLayoutYAxisAnchor) {
        button.translatesAutoresizingMaskIntoConstraints = false

        view.addSubview(button)

        NSLayoutConstraint.activate([
            button.bottomAnchor.constraint(equalTo: bottomAnchor, constant: Constants.padding),
            button.heightAnchor.constraint(equalToConstant: Constants.heightWidth),
            button.widthAnchor.constraint(equalToConstant: Constants.heightWidth),
            button.trailingAnchor.constraint(equalTo: trailingAnchor, constant: Constants.padding)
        ])

        button.addTarget(self, action: #selector(showCreateSheet), for: .touchUpInside)
    }

    @objc private func showCreateSheet() {
        shouldShowNotice = false
        hideNotice()

        guard let viewController = viewController else { return }
        let actionSheetVC = actionSheetController(for: viewController.traitCollection)
        viewController.present(actionSheetVC, animated: true, completion: {
            WPAnalytics.track(.createSheetShown)
        })
    }

    private func actionSheetController(for traitCollection: UITraitCollection) -> UIViewController {
        let postsButton = ActionSheetButton(title: NSLocalizedString("Blog post", comment: "Create new Blog Post button title"),
                                            image: .gridicon(.posts),
                                            identifier: "blogPostButton",
                                            target: self,
                                            selector: #selector(showNewPost))
        let pagesButton = ActionSheetButton(title: NSLocalizedString("Site page", comment: "Create new Site Page button title"),
                                            image: .gridicon(.pages),
                                            identifier: "sitePageButton",
                                            target: self,
                                            selector: #selector(showNewPage))
        let actionSheetController = ActionSheetViewController(headerTitle: NSLocalizedString("Create New", comment: "Create New header text"),
                                                              buttons: [postsButton, pagesButton])

        setupPresentation(on: actionSheetController, for: traitCollection)

        return actionSheetController
    }

    private func setupPresentation(on viewController: UIViewController, for traitCollection: UITraitCollection) {
        if traitCollection.horizontalSizeClass == .regular && traitCollection.verticalSizeClass == .regular {
            viewController.modalPresentationStyle = .popover
        } else {
            viewController.modalPresentationStyle = .custom
        }

        viewController.popoverPresentationController?.sourceView = self.button
        viewController.popoverPresentationController?.sourceRect = self.button.bounds.offsetBy(dx: 0, dy: Constants.popoverOffset)
        viewController.transitioningDelegate = self
    }

    private func hideNotice() {
        if let container = noticeContainerView {
            NoticePresenter.dismiss(container: container)
        }
    }

    @objc func hideCreateButton() {
        hideNotice()

        if UIAccessibility.isReduceMotionEnabled {
            button.isHidden = true
        } else {
            button.springAnimation(toShow: false)
        }
    }

    @objc func showCreateButton() {
        noticeContainerView = noticeAnimator.present(notice: notice, in: viewController!.view, sourceView: button)
        if UIAccessibility.isReduceMotionEnabled {
            button.isHidden = false
        } else {
            button.springAnimation(toShow: true)
        }
    }

    @objc func showNewPost() {
        newPost()
    }

    @objc func showNewPage() {
        newPage()
    }
}

// MARK: Tranisitioning Delegate

extension CreateButtonCoordinator: UIViewControllerTransitioningDelegate {
    public func animationController(forPresented presented: UIViewController, presenting: UIViewController, source: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return BottomSheetAnimationController(transitionType: .presenting)
    }

    public func animationController(forDismissed dismissed: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        return BottomSheetAnimationController(transitionType: .dismissing)
    }

    public func presentationController(forPresented presented: UIViewController, presenting: UIViewController?, source: UIViewController) -> UIPresentationController? {
        let presentationController = BottomSheetPresentationController(presentedViewController: presented, presenting: presenting)
        return presentationController
    }

    public func interactionControllerForDismissal(using animator: UIViewControllerAnimatedTransitioning) -> UIViewControllerInteractiveTransitioning? {
        return (viewController?.presentedViewController?.presentationController as? BottomSheetPresentationController)?.interactionController
    }
}
