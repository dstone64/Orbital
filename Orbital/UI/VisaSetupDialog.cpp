#include "VisaSetupDialog.h"

VisaSetupDialog::VisaSetupDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui.setupUi(this);
}

VisaSetupDialog::~VisaSetupDialog()
{
}

void VisaSetupDialog::GenerateVisaEntries(const QStringList& visaOptions)
{
	RemoveAll();
	for (int i = visaOptions.size(); i > 0; --i)
		AddVisa(visaOptions);
}

QStringList VisaSetupDialog::VisaAssignments()
{
	QStringList visaAssignments;

	for (auto itr = this->visaEntries.begin(); itr != this->visaEntries.end(); ++itr)
		visaAssignments.append((*itr)->CurrentText());

	return visaAssignments;
}

void VisaSetupDialog::on_pushButton_save_clicked()
{
	for (auto itr = this->visaEntries.begin(); itr != this->visaEntries.end(); ++itr)
		(*itr)->Set();

	this->close();
}

void VisaSetupDialog::on_pushButton_cancel_clicked()
{
	for (auto itr = this->visaEntries.begin(); itr != this->visaEntries.end(); ++itr)
		(*itr)->Reset();

	this->close();
}

void VisaSetupDialog::AddVisa(const QStringList& visaOptions)
{
	VisaEntry *visaEntry = new VisaEntry(this->ui.scrollAreaWidgetContents, visaOptions);
	this->ui.verticalLayout_scrollAreaWidgetContents->insertWidget(this->visaEntries.size(), visaEntry->Frame());
	this->visaEntries.push_back(visaEntry);
}

void VisaSetupDialog::RemoveAll()
{
	for (int i = this->visaEntries.size(); i > 0; --i) {
		this->ui.verticalLayout_scrollAreaWidgetContents->removeWidget(this->visaEntries.back()->Frame());
		delete this->visaEntries.back();
		this->visaEntries.pop_back();
	}
}

VisaSetupDialog::VisaEntry::VisaEntry(QWidget *parent, const QStringList& visaOptions) : resetVal(0)
{
	this->frame = new QFrame(parent);
	this->layout = new QHBoxLayout(this->frame);
	this->label = new QLabel(this->frame);
	this->comboBox = new QComboBox(this->frame);

	QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(this->label->sizePolicy().hasHeightForWidth());

	QFont font;
	font.setPointSize(10);

	this->comboBox->addItems(visaOptions);

	this->layout->setSpacing(6);
	this->layout->setContentsMargins(11, 11, 11, 11);
	this->layout->addWidget(label);
	this->layout->addWidget(comboBox);
}

VisaSetupDialog::VisaEntry::VisaEntry(const VisaEntry& src)
{

}

VisaSetupDialog::VisaEntry::~VisaEntry()
{
	delete this->frame;
}