#include "EDLineEdit.h"

EDLineEdit::EDLineEdit() {
    QObject::connect(this, SIGNAL(returnPressed()), qApp, SLOT(quit()));
}
