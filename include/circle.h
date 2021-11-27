#pragma once
#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>

class Circle : public QWidget
{
    Q_OBJECT

public:
    Circle() = default;

    Circle(QWidget *parent);

    void paintEvent(QPaintEvent *e) override;

    QSize minimumSizeHint() const override;

    void setRed();

    void setYellow();

    void setGreen();

private:
    QPixmap mCircleRed;
    QPixmap mCircleGreen;
    QPixmap mCircleYellow;
    QPixmap mCurrentColor;
};
