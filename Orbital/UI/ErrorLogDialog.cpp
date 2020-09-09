#include "ErrorLogDialog.h"

ErrorLogDialog::ErrorLogDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui.setupUi(this);
}

ErrorLogDialog::~ErrorLogDialog()
{
}
