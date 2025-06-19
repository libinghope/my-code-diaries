// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include <QDir>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView> //Not using QQmlApplicationEngine because many examples don't have a Window{}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("QtProject");
    app.setOrganizationDomain("qt-project.org");
    app.setApplicationName(QFileInfo(app.applicationFilePath()).baseName());

    QQuickView view;

    // 平台相关的导入路径处理（原宏展开内容）
#ifdef Q_OS_MACOS
    view.engine()->addImportPath(app.applicationDirPath() + QStringLiteral("/../PlugIns"));
#endif

    // 处理 QT_QUICK_CORE_PROFILE 环境变量（原宏展开内容）
    if (qEnvironmentVariableIntValue("QT_QUICK_CORE_PROFILE"))
    {
        QSurfaceFormat f = view.format();
        f.setProfile(QSurfaceFormat::CoreProfile);
        f.setVersion(4, 4);
        view.setFormat(f);
    }

    // 处理 QT_QUICK_MULTISAMPLE 环境变量（原宏展开内容）
    if (qEnvironmentVariableIntValue("QT_QUICK_MULTISAMPLE"))
    {
        QSurfaceFormat f = view.format();
        f.setSamples(4);
        view.setFormat(f);
    }

    // 连接引擎退出信号（原宏展开内容）
    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);

    // 创建 QML 文件选择器（原宏展开内容）
    new QQmlFileSelector(view.engine(), &view);

    // 设置 QML 源文件（原宏展开内容）
    view.setSource(QUrl("qrc:/qt/qml/samegame/samegame.qml"));
    if (view.status() == QQuickView::Error)
        return -1;

    // 设置调整大小模式并显示视图（原宏展开内容）
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}