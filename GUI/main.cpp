#include <QtGui>
#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "EDListLayout.h"

 int main(int argv, char **args)
{
    QApplication app(argv, args);

    // interface elements
    QLabel *title = new QLabel;
    QVBoxLayout *listItems = new QVBoxLayout; // to be changed from QVBoxLAyout to EDListLayout
    QLabel *feedbackBox = new QLabel;
    QLineEdit *inputField = new QLineEdit;
    QPushButton *quitButton = new QPushButton("&Quit");

    title->setText("EASYDone");
    title->setAlignment(Qt::AlignCenter);

    // interface element functions
    QObject::connect(inputField, SIGNAL(returnPressed()),  qApp, SLOT(quit())); // technique: subclass our function to some widget or stuff to add slots.
    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    // interface layout
    QVBoxLayout *windowLayout = new QVBoxLayout;
    windowLayout->addWidget(title);
    windowLayout->addLayout(listItems);
    windowLayout->addWidget(feedbackBox);
    windowLayout->addWidget(inputField);
    windowLayout->addWidget(quitButton);

    QWidget window;
    window.setLayout(windowLayout);

    window.show();

    return app.exec();
}
