struct ActionSheetButton {
    let title: String
    let image: UIImage
    let identifier: String
    let target: Any?
    let selector: Selector
}

class ActionSheetViewController: UIViewController {

    enum Constants {
        static let buttonSpacing: CGFloat = 8
        static let additionalSafeAreaInsetsRegular: UIEdgeInsets = UIEdgeInsets(top: 20, left: 0, bottom: 20, right: 0)
        static let minimumWidth: CGFloat = 300

        enum Header {
            static let spacing: CGFloat = 16
            static let insets: UIEdgeInsets = UIEdgeInsets(top: 0, left: 18, bottom: 0, right: 18)
        }

        enum Button {
            static let height: CGFloat = 54
            static let contentInsets: UIEdgeInsets = UIEdgeInsets(top: 0, left: 18, bottom: 0, right: 35)
            static let titleInsets: UIEdgeInsets = UIEdgeInsets(top: 0, left: 16, bottom: 0, right: 0)
            static let imageTintColor: UIColor = .neutral(.shade30)
            static let font: UIFont = .preferredFont(forTextStyle: .callout)
            static let textColor: UIColor = .text
        }

        enum Stack {
            static let insets: UIEdgeInsets = UIEdgeInsets(top: 5, left: 0, bottom: 0, right: 0)
        }
    }

    let buttons: [ActionSheetButton]
    let headerTitle: String

    init(headerTitle: String, buttons: [ActionSheetButton]) {
        self.headerTitle = headerTitle
        self.buttons = buttons
        super.init(nibName: nil, bundle: nil)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    @objc func buttonPressed() {
        dismiss(animated: true, completion: nil)
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        view.backgroundColor = .basicBackground

        let headerLabelView = UIView()
        let headerLabel = UILabel()
        headerLabelView.addSubview(headerLabel)
        headerLabelView.pinSubviewToAllEdges(headerLabel, insets: Constants.Header.insets)

        headerLabel.font = WPStyleGuide.fontForTextStyle(.headline)
        headerLabel.text = headerTitle
        headerLabel.translatesAutoresizingMaskIntoConstraints = false

        let buttonViews = buttons.map({ (buttonInfo) -> UIButton in
            return button(buttonInfo)
        })

        let buttonConstraints = buttonViews.map { button in
            return button.heightAnchor.constraint(equalToConstant: Constants.Button.height)
        }

        NSLayoutConstraint.activate(buttonConstraints + [
            headerLabelView.heightAnchor.constraint(equalToConstant: Constants.Button.height)
        ])

        let stackView = UIStackView(arrangedSubviews: [
            headerLabelView
        ] + buttonViews)

        stackView.setCustomSpacing(Constants.Header.spacing, after: headerLabelView)

        buttonViews.forEach { button in
            stackView.setCustomSpacing(Constants.buttonSpacing, after: button)
        }

        stackView.translatesAutoresizingMaskIntoConstraints = false
        stackView.axis = .vertical

        view.addSubview(stackView)
        let stackViewConstraints = [
            view.safeAreaLayoutGuide.leadingAnchor.constraint(equalTo: stackView.leadingAnchor, constant: -Constants.Stack.insets.left),
            view.safeAreaLayoutGuide.trailingAnchor.constraint(equalTo: stackView.trailingAnchor, constant: Constants.Stack.insets.right),
            view.safeAreaLayoutGuide.topAnchor.constraint(equalTo: stackView.topAnchor, constant: -Constants.Stack.insets.top),
        ]

//        let bottomAnchor = view.safeAreaLayoutGuide.bottomAnchor.constraint(equalTo: stackView.bottomAnchor, constant: Constants.Stack.insets.bottom)
//        bottomAnchor.priority = .defaultHigh

        NSLayoutConstraint.activate(stackViewConstraints) //+ [bottomAnchor])
    }

    func button(_ info: ActionSheetButton) -> UIButton {
        let button = UIButton(type: .custom)
        button.setTitle(info.title, for: .normal)
        button.titleLabel?.font = Constants.Button.font
        button.setTitleColor(Constants.Button.textColor, for: .normal)
        button.setImage(info.image, for: .normal)
        button.imageView?.tintColor = Constants.Button.imageTintColor
        button.setBackgroundImage(UIImage(color: .divider), for: .highlighted)
        button.titleEdgeInsets = Constants.Button.titleInsets
        button.naturalContentHorizontalAlignment = .leading
        button.contentEdgeInsets = Constants.Button.contentInsets
        button.addTarget(info.target, action: info.selector, for: .touchUpInside)
        button.accessibilityIdentifier = info.identifier
        button.translatesAutoresizingMaskIntoConstraints = false
        button.flipInsetsForRightToLeftLayoutDirection()
        return button
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
//        preferredContentSize = CGSize(width: Constants.minimumWidth, height: view.systemLayoutSizeFitting(UIView.layoutFittingCompressedSize).height)
    }
}

// MARK: - DrawerPresentable

extension ActionSheetViewController: DrawerPresentable {
    var expandedHeight: DrawerHeight {
        return collapsedHeight
    }

    var collapsedHeight: DrawerHeight {
        let height = view.subviews.first!.systemLayoutSizeFitting(UIView.layoutFittingCompressedSize).height + view.safeAreaInsets.bottom
        return .contentHeight(height)
    }

    var allowsUserTransition: Bool {
        return false
    }

    var scrollableView: UIScrollView? {
        return nil
    }
}
