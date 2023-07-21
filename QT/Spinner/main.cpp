#include <QSpinBox>
#include <QSlider>
#include <QApplication>
#include <QObject>
#include <QBoxLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget* window = new QWidget;
    window->setWindowTitle("Enter Your Age");

    QSpinBox* spinbox = new QSpinBox;
    spinbox->setRange(0, 130);

    QSlider* slider = new QSlider;
    slider->setRange(0,130);

    QObject::connect(spinbox,
                     SIGNAL(valueChanged(int)),
                     slider,
                     SLOT(setValue(int)));

    QObject::connect(slider,
                     SIGNAL(valueChanged(int)),
                     spinbox,
                     SLOT(setValue(int)));

    spinbox->setValue(111);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(spinbox);
    layout->addWidget(slider);
    window->setLayout(layout);
    window->show();

    return app.exec();
}
