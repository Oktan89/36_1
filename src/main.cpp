#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QSlider>
#include "circle.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    QWidget *circle = new Circle(window);
    
     
    QSlider *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);
    
    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);
    
    QObject::connect(slider, &QSlider::valueChanged, [circle, slider](int newValue)
        {
            Circle *c = dynamic_cast<Circle*>(circle);
            if(c)
            {
                if(newValue >=0 && newValue < 33)
                    c->setGreen();
                else if(newValue >=33 && newValue < 36)
                    c->setYellow();
                else if(newValue >=36 && newValue <= 100)
                    c->setRed();
            }
            
        });
    window->setFixedSize(250, 280);
    window->show();

    return app.exec();
}