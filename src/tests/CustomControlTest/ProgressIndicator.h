//
// Created by fluty on 2023/8/14.
//

#ifndef DATASET_TOOLS_PROGRESSINDICATOR_H
#define DATASET_TOOLS_PROGRESSINDICATOR_H

#include <QWidget>
#include <QPropertyAnimation>
#include "WidgetsGlobal/QMWidgetsGlobal.h"

class QMWIDGETS_EXPORT ProgressIndicator : public QWidget {
    Q_OBJECT
    Q_PROPERTY(double minimum READ minimum WRITE setMinimum)
    Q_PROPERTY(double maximum READ maximum WRITE setMaximum)
    Q_PROPERTY(double value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(double secondaryValue READ secondaryValue WRITE setSecondaryValue NOTIFY secondaryValueChanged)
    Q_PROPERTY(double currentTaskValue READ currentTaskValue WRITE setValue NOTIFY currentTaskValueChanged)
//    Q_PROPERTY(bool invertedAppearance READ invertedAppearance WRITE setInvertedAppearance)
    Q_PROPERTY(int thumbProgress READ thumbProgress WRITE setThumbProgress)
    Q_PROPERTY(bool indeterminate READ indeterminate WRITE setIndeterminate)

public:
    enum IndicatorStyle {
        HorizontalBar,
//        VerticalBar,
        Ring
    };

    enum TaskStatus {
        Normal,
        Warning,
        Error
    };

    explicit ProgressIndicator(QWidget *parent = nullptr);
    explicit ProgressIndicator(IndicatorStyle indicatorStyle,QWidget *parent = nullptr);
    ~ProgressIndicator();

    double minimum() const;
    double maximum() const;
    double value() const;
    double secondaryValue() const;
    double currentTaskValue() const;
    bool indeterminate() const;
//
//    QSize sizeHint() const override;
//    QSize minimumSizeHint() const override;
//
//    Qt::Orientation orientation() const;
//
//    void setInvertedAppearance(bool invert);
//    bool invertedAppearance() const;
//
//    void setFormat(const QString &format);
//    void resetFormat();
//    QString format() const;

public slots:
    void reset();
    void setRange(double minimum, double maximum);
    void setMinimum(double minimum);
    void setMaximum(double maximum);
    void setValue(double value);
    void setSecondaryValue(double value);
    void setCurrentTaskValue(double value);
    void setIndeterminate(bool on);

signals:
    void valueChanged(int value);
    void secondaryValueChanged(int value);
    void currentTaskValueChanged(int value);

protected:
    QColor colorInactive = QColor(217, 217, 217);

    QColor colorValueNormal = QColor(112, 156, 255);
    QColor colorSecondaryNormal = QColor(159, 189, 255);
    QColor colorCurrentTaskNormal = QColor(113, 218, 255);

    QColor colorValueWarning = QColor(255, 175, 95);
    QColor colorSecondaryWarning = QColor(255, 204, 153);
    QColor colorCurrentTaskWarning = QColor(255, 218, 113);

    QColor colorValueError = QColor(255, 124, 128);
    QColor colorSecondaryError = QColor(255, 171, 173);
    QColor colorCurrentTaskError = QColor(255, 171, 221);

    IndicatorStyle m_indicatorStyle = HorizontalBar;
    double m_max = 100;
    double m_min = 0;
    double m_value = 0;
    double m_secondaryValue = 0;
    double m_currentTaskValue = 0;
    bool m_indeterminate = false;
    int m_thumbProgress = 0;
//    bool m_invertedAppearance = false;
//    QTimer *m_timer;
    QPropertyAnimation *m_animation;

    void initUi(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;

private:
    int thumbProgress() const;
    void setThumbProgress(int x);
};



#endif // DATASET_TOOLS_PROGRESSINDICATOR_H
