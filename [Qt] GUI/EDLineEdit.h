// EDLineEdit is a QWidget
// Done by: JJ

#ifndef EDLINEEDIT_H
#define EDLINEEDIT_H

#include <QLineEdit>
#include <QVBoxLayout>

class EDLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    EDLineEdit();

signals:
    void returnPressed();

public slots:


};

#endif // EDLINEEDIT_H
