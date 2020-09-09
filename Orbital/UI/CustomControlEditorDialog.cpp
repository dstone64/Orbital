#include "CustomControlEditorDialog.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>

CustomControlEditorDialog::CustomControlEditorDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint), config(nullptr)
{
	ui.setupUi(this);

	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);

	for (int i = 0; i < N_CUSTOMCONTROLS; ++i) {
		QFrame *frame;
		QHBoxLayout *layout;
		QLabel *label;
		QLineEdit *lineEdit;

		frame = new QFrame(this->ui.frame_customControlNames);
		frame->setFrameShape(QFrame::StyledPanel);
		frame->setFrameShadow(QFrame::Plain);

		layout = new QHBoxLayout(frame);
		layout->setSpacing(6);
		layout->setContentsMargins(11, 11, 11, 11);

		label = new QLabel(frame);
		sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
		label->setSizePolicy(sizePolicy);
		label->setMinimumSize(QSize(64, 0));
		label->setText(QString("customFn").append(QString::number(i + 1)));

		lineEdit = new QLineEdit(frame);
		this->customControlLineEdits[i] = lineEdit;

		layout->addWidget(label);
		layout->addWidget(lineEdit);
		ui.gridLayout_customControlNames->addWidget(frame, (i / 2), (i % 2));
	}
}

CustomControlEditorDialog::~CustomControlEditorDialog()
{
}

void CustomControlEditorDialog::Setup(AppConfig *config)
{
	this->config = config;

	for (int i = 0; i < N_CUSTOMCONTROLS; ++i) {
		this->customControlNames.append(
			config->get(std::string("customFn").append(std::to_string(i)), QString("customFn").append(QString::number(i + 1)))
		);
		this->customControlLineEdits[i]->setText(this->customControlNames.last());
	}
}

void CustomControlEditorDialog::UpdateConfig() const
{
	for (int i = 0; i < N_CUSTOMCONTROLS; ++i) {
		config->get(std::string("customFn").append(std::to_string(i))) = this->customControlLineEdits[i]->text();
	}
}

void CustomControlEditorDialog::on_pushButton_save_clicked()
{
	for (unsigned int i = 0; i < N_CUSTOMCONTROLS; ++i) {
		this->customControlNames[i] = this->customControlLineEdits[i]->text();
	}
	emit Signal_CustomControlsUpdated();
	this->close();
}

void CustomControlEditorDialog::on_pushButton_cancel_clicked()
{
	for (unsigned int i = 0; i < N_CUSTOMCONTROLS; ++i) {
		this->customControlLineEdits[i]->setText(this->customControlNames[i]);
	}
	this->close();
}

void CustomControlEditorDialog::SetName(size_t customControl, const QString& newName)
{
	if (customControl >= N_CUSTOMCONTROLS)
		return;

	customControlLineEdits[customControl]->setText(newName);
	customControlNames[customControl] = QString(newName);
	emit Signal_CustomControlsUpdated();
}

void CustomControlEditorDialog::SetAll(const QStringList& newNames)
{
	if (newNames.size() != N_CUSTOMCONTROLS)
		return;

	for (int i = 0; i < N_CUSTOMCONTROLS; ++i) {
		customControlLineEdits[i]->setText(newNames.at(i));
		customControlNames[i] = QString(newNames.at(i));
	}
	emit Signal_CustomControlsUpdated();
}