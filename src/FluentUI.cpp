#include "FluentUI.h"

#include <QGuiApplication>
#include "WindowLifecycle.h"
#include "Def.h"
#include "FluApp.h"
#include "FluColors.h"
#include "FluTheme.h"
#include "FluTools.h"
#include "FluTextStyle.h"
#include "FluHttp.h"
#include "FluHttpInterceptor.h"
#include "FluWatermark.h"
#include "FluCaptcha.h"
#include "FluEventBus.h"
#include "FluTreeModel.h"
#include "FluViewModel.h"
#include "Screenshot.h"
#include "FluRectangle.h"
#include "QRCode.h"

constexpr int major_version = 1;
constexpr int minor_version = 0;
auto uri = "FluentUI";

FluentUI* FluentUI::m_instance = nullptr;

FluentUI *FluentUI::getInstance()
{
    if(FluentUI::m_instance == nullptr){
        FluentUI::m_instance = new FluentUI;
    }
    return FluentUI::m_instance;
}

void FluentUI::registerTypes(QQmlEngine *engine){
    initializeEngine(engine,uri);
    registerTypes(uri);
}

void FluentUI::registerTypes(const char *uri){
#if (QT_VERSION < QT_VERSION_CHECK(6, 2, 0))
    Q_INIT_RESOURCE(fluentui);
#endif
    qmlRegisterType<WindowLifecycle>(uri,major_version,minor_version,"WindowLifecycle");
    qmlRegisterType<QRCode>(uri,major_version,minor_version,"QRCode");
    qmlRegisterType<FluCaptcha>(uri,major_version,minor_version,"FluCaptcha");
    qmlRegisterType<FluWatermark>(uri,major_version,minor_version,"FluWatermark");
    qmlRegisterType<ScreenshotBackground>(uri,major_version,minor_version,"ScreenshotBackground");
    qmlRegisterType<Screenshot>(uri,major_version,minor_version,"Screenshot");
    qmlRegisterType<FluColorSet>(uri,major_version,minor_version,"FluColorSet");
    qmlRegisterType<FluHttpInterceptor>(uri,major_version,minor_version,"FluHttpInterceptor");
    qmlRegisterType<FluHttp>(uri,major_version,minor_version,"FluHttp");
    qmlRegisterType<HttpCallable>(uri,major_version,minor_version,"HttpCallable");
    qmlRegisterType<HttpRequest>(uri,major_version,minor_version,"HttpRequest");
    qmlRegisterType<FluEvent>(uri,major_version,minor_version,"FluEvent");
    qmlRegisterType<FluViewModel>(uri,major_version,minor_version,"FluViewModel");
    qmlRegisterType<FluTreeModel>(uri,major_version,minor_version,"FluTreeModel");
    qmlRegisterType<FluRectangle>(uri,major_version,minor_version,"FluRectangle");

    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/ColorPicker/ColorPicker.qml"),uri,major_version,minor_version,"ColorPicker");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/ColorPicker/Content/Checkerboard.qml"),uri,major_version,minor_version,"Checkerboard");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/ColorPicker/Content/ColorSlider.qml"),uri,major_version,minor_version,"ColorSlider");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/ColorPicker/Content/NumberBox.qml"),uri,major_version,minor_version,"NumberBox");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/ColorPicker/Content/PanelBorder.qml"),uri,major_version,minor_version,"PanelBorder");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/ColorPicker/Content/SBPicker.qml"),uri,major_version,minor_version,"SBPicker");

    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluAcrylic.qml"),uri,major_version,minor_version,"FluAcrylic");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluAppBar.qml"),uri,major_version,minor_version,"FluAppBar");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluArea.qml"),uri,major_version,minor_version,"FluArea");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluAutoSuggestBox.qml"),uri,major_version,minor_version,"FluAutoSuggestBox");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluBadge.qml"),uri,major_version,minor_version,"FluBadge");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluBreadcrumbBar.qml"),uri,major_version,minor_version,"FluBreadcrumbBar");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluButton.qml"),uri,major_version,minor_version,"FluButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluCalendarPicker.qml"),uri,major_version,minor_version,"FluCalendarPicker");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluCalendarView.qml"),uri,major_version,minor_version,"FluCalendarView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluCarousel.qml"),uri,major_version,minor_version,"FluCarousel");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluChart.qml"),uri,major_version,minor_version,"FluChart");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluCheckBox.qml"),uri,major_version,minor_version,"FluCheckBox");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluColorPicker.qml"),uri,major_version,minor_version,"FluColorPicker");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluColorView.qml"),uri,major_version,minor_version,"FluColorView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluComboBox.qml"),uri,major_version,minor_version,"FluComboBox");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluContentDialog.qml"),uri,major_version,minor_version,"FluContentDialog");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluContentPage.qml"),uri,major_version,minor_version,"FluContentPage");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluControl.qml"),uri,major_version,minor_version,"FluControl");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluCopyableText.qml"),uri,major_version,minor_version,"FluCopyableText");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluDatePicker.qml"),uri,major_version,minor_version,"FluDatePicker");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluDivider.qml"),uri,major_version,minor_version,"FluDivider");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluDropDownButton.qml"),uri,major_version,minor_version,"FluDropDownButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluExpander.qml"),uri,major_version,minor_version,"FluExpander");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluFilledButton.qml"),uri,major_version,minor_version,"FluFilledButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluFlipView.qml"),uri,major_version,minor_version,"FluFlipView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluFocusRectangle.qml"),uri,major_version,minor_version,"FluFocusRectangle");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluIcon.qml"),uri,major_version,minor_version,"FluIcon");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluIconButton.qml"),uri,major_version,minor_version,"FluIconButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluImage.qml"),uri,major_version,minor_version,"FluImage");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluInfoBar.qml"),uri,major_version,minor_version,"FluInfoBar");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluItemDelegate.qml"),uri,major_version,minor_version,"FluItemDelegate");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluMenu.qml"),uri,major_version,minor_version,"FluMenu");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluMenuBar.qml"),uri,major_version,minor_version,"FluMenuBar");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluMenuBarItem.qml"),uri,major_version,minor_version,"FluMenuBarItem");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluMenuItem.qml"),uri,major_version,minor_version,"FluMenuItem");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluMenuSeparator.qml"),uri,major_version,minor_version,"FluMenuSeparator");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluMultilineTextBox.qml"),uri,major_version,minor_version,"FluMultilineTextBox");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluNavigationView.qml"),uri,major_version,minor_version,"FluNavigationView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluObject.qml"),uri,major_version,minor_version,"FluObject");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPage.qml"),uri,major_version,minor_version,"FluPage");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPagination.qml"),uri,major_version,minor_version,"FluPagination");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPaneItem.qml"),uri,major_version,minor_version,"FluPaneItem");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPaneItemEmpty.qml"),uri,major_version,minor_version,"FluPaneItemEmpty");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPaneItemExpander.qml"),uri,major_version,minor_version,"FluPaneItemExpander");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPaneItemHeader.qml"),uri,major_version,minor_version,"FluPaneItemHeader");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPaneItemSeparator.qml"),uri,major_version,minor_version,"FluPaneItemSeparator");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPasswordBox.qml"),uri,major_version,minor_version,"FluPasswordBox");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPivot.qml"),uri,major_version,minor_version,"FluPivot");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPivotItem.qml"),uri,major_version,minor_version,"FluPivotItem");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluPopup.qml"),uri,major_version,minor_version,"FluPopup");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluProgressBar.qml"),uri,major_version,minor_version,"FluProgressBar");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluProgressRing.qml"),uri,major_version,minor_version,"FluProgressRing");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluQRCode.qml"),uri,major_version,minor_version,"FluQRCode");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluRadioButton.qml"),uri,major_version,minor_version,"FluRadioButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluRadioButtons.qml"),uri,major_version,minor_version,"FluRadioButtons");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluRatingControl.qml"),uri,major_version,minor_version,"FluRatingControl");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluRemoteLoader.qml"),uri,major_version,minor_version,"FluRemoteLoader");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluScreenshot.qml"),uri,major_version,minor_version,"FluScreenshot");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluScrollBar.qml"),uri,major_version,minor_version,"FluScrollBar");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluScrollIndicator.qml"),uri,major_version,minor_version,"FluScrollIndicator");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluScrollablePage.qml"),uri,major_version,minor_version,"FluScrollablePage");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluShadow.qml"),uri,major_version,minor_version,"FluShadow");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluSlider.qml"),uri,major_version,minor_version,"FluSlider");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluSpinBox.qml"),uri,major_version,minor_version,"FluSpinBox");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluStatusView.qml"),uri,major_version,minor_version,"FluStatusView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTabView.qml"),uri,major_version,minor_version,"FluTabView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTableModelColumn.qml"),uri,major_version,minor_version,"FluTableModelColumn");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTableView.qml"),uri,major_version,minor_version,"FluTableView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluText.qml"),uri,major_version,minor_version,"FluText");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTextBox.qml"),uri,major_version,minor_version,"FluTextBox");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTextBoxBackground.qml"),uri,major_version,minor_version,"FluTextBoxBackground");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTextBoxMenu.qml"),uri,major_version,minor_version,"FluTextBoxMenu");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTextButton.qml"),uri,major_version,minor_version,"FluTextButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTimePicker.qml"),uri,major_version,minor_version,"FluTimePicker");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTimeline.qml"),uri,major_version,minor_version,"FluTimeline");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluToggleButton.qml"),uri,major_version,minor_version,"FluToggleButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluToggleSwitch.qml"),uri,major_version,minor_version,"FluToggleSwitch");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTooltip.qml"),uri,major_version,minor_version,"FluTooltip");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTour.qml"),uri,major_version,minor_version,"FluTour");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluTreeView.qml"),uri,major_version,minor_version,"FluTreeView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluWindow.qml"),uri,major_version,minor_version,"FluWindow");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluRangeSlider.qml"),uri,major_version,minor_version,"FluRangeSlider");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluStaggeredView.qml"),uri,major_version,minor_version,"FluStaggeredView");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluProgressButton.qml"),uri,major_version,minor_version,"FluProgressButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluLoadingButton.qml"),uri,major_version,minor_version,"FluLoadingButton");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluClip.qml"),uri,major_version,minor_version,"FluClip");
    qmlRegisterType(QUrl("qrc:/qt/qml/FluentUI/Controls/FluLoader.qml"),uri,major_version,minor_version,"FluLoader");


    qmlRegisterUncreatableMetaObject(Fluent_Awesome::staticMetaObject,  uri,major_version,minor_version,"FluentIcons", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluHttpType::staticMetaObject,  uri,major_version,minor_version,"FluHttpType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluThemeType::staticMetaObject,  uri,major_version,minor_version,"FluThemeType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluPageType::staticMetaObject,  uri,major_version,minor_version,"FluPageType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluWindowType::staticMetaObject,  uri,major_version,minor_version,"FluWindowType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluTreeViewType::staticMetaObject,  uri,major_version,minor_version,"FluTreeViewType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluStatusViewType::staticMetaObject,  uri,major_version,minor_version,"FluStatusViewType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluContentDialogType::staticMetaObject,  uri,major_version,minor_version,"FluContentDialogType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluTimePickerType::staticMetaObject,  uri,major_version,minor_version,"FluTimePickerType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluCalendarViewType::staticMetaObject,  uri,major_version,minor_version,"FluCalendarViewType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluTabViewType::staticMetaObject,  uri,major_version,minor_version,"FluTabViewType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluNavigationViewType::staticMetaObject,  uri,major_version,minor_version,"FluNavigationViewType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluTimelineType::staticMetaObject,  uri,major_version,minor_version,"FluTimelineType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluScreenshotType::staticMetaObject,  uri,major_version,minor_version,"FluScreenshotType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(FluViewModelType::staticMetaObject,  uri,major_version,minor_version,"FluViewModelType", "Access to enums & flags only");

    qmlRegisterModule(uri,major_version,minor_version);
}

void FluentUI::initializeEngine(QQmlEngine *engine, const char *uri){
#ifdef Q_OS_WIN
    QFont font;
    font.setFamily("Microsoft YaHei");
    QGuiApplication::setFont(font);
#endif
    FluApp* app = FluApp::getInstance();
    engine->rootContext()->setContextProperty("FluApp",app);
    FluColors* colors = FluColors::getInstance();
    engine->rootContext()->setContextProperty("FluColors",colors);
    FluTheme* theme = FluTheme::getInstance();
    engine->rootContext()->setContextProperty("FluTheme",theme);
    FluTools* tools = FluTools::getInstance();
    engine->rootContext()->setContextProperty("FluTools",tools);
    FluTextStyle* textStyle = FluTextStyle::getInstance();
    engine->rootContext()->setContextProperty("FluTextStyle",textStyle);
    FluEventBus* eventBus = FluEventBus::getInstance();
    engine->rootContext()->setContextProperty("FluEventBus",eventBus);
    engine->addImportPath("qrc:/qt/qml");
}
