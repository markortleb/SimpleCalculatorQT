#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QChar>
#include <string>
#include <stack>
#include "SimpleCalculator.h"
#include "utility.h"


SimpleCalculator::SimpleCalculator(QWidget *parent) : QDialog(parent)
{
	
	prevAnsInBox = false;

	calculateText = new QLineEdit;
	periodButton = new QPushButton(tr("."));
	zeroButton = new QPushButton(tr("0"));
	oneButton = new QPushButton(tr("1"));
	twoButton = new QPushButton(tr("2"));
	threeButton = new QPushButton(tr("3"));
	fourButton = new QPushButton(tr("4"));
	fiveButton = new QPushButton(tr("5"));
	sixButton = new QPushButton(tr("6"));
	sevenButton = new QPushButton(tr("7"));
	eightButton = new QPushButton(tr("8"));
	nineButton = new QPushButton(tr("9"));
	addButton = new QPushButton(tr("+"));
	divideButton = new QPushButton(tr("/"));
	multiplyButton = new QPushButton(tr("*"));
	subtractButton = new QPushButton(tr("-"));
	calculateButton = new QPushButton(tr("Calculate"));
	openParenthesesButton = new QPushButton(tr("("));
	closeParenthesesButton = new QPushButton(tr(")"));
	exponentButton = new QPushButton(tr("^"));
	clearButton = new QPushButton(tr("CLR"));


	connect(periodButton, SIGNAL(clicked()), this, SLOT(periodButtonClicked()));
	connect(zeroButton, SIGNAL(clicked()), this, SLOT(zeroButtonClicked()));
	connect(oneButton, SIGNAL(clicked()), this, SLOT(oneButtonClicked()));
	connect(twoButton, SIGNAL(clicked()), this, SLOT(twoButtonClicked()));
	connect(threeButton, SIGNAL(clicked()), this, SLOT(threeButtonClicked()));
	connect(fourButton, SIGNAL(clicked()), this, SLOT(fourButtonClicked()));
	connect(fiveButton, SIGNAL(clicked()), this, SLOT(fiveButtonClicked()));
	connect(sixButton, SIGNAL(clicked()), this, SLOT(sixButtonClicked()));
	connect(sevenButton, SIGNAL(clicked()), this, SLOT(sevenButtonClicked()));
	connect(eightButton, SIGNAL(clicked()), this, SLOT(eightButtonClicked()));
	connect(nineButton, SIGNAL(clicked()), this, SLOT(nineButtonClicked()));
	connect(addButton, SIGNAL(clicked()), this, SLOT(addButtonClicked()));
	connect(subtractButton, SIGNAL(clicked()), this, SLOT(subtractButtonClicked()));
	connect(multiplyButton, SIGNAL(clicked()), this, SLOT(multiplyButtonClicked()));
	connect(divideButton, SIGNAL(clicked()), this, SLOT(divideButtonClicked()));
	connect(openParenthesesButton, SIGNAL(clicked()), this, SLOT(openParenthesesClicked()));
	connect(closeParenthesesButton, SIGNAL(clicked()), this, SLOT(closeParenthesesClicked()));
	connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));
	connect(calculateButton, SIGNAL(clicked()), this, SLOT(calculate()));
	connect(exponentButton, SIGNAL(clicked()), this, SLOT(exponentButtonClicked()));






	QHBoxLayout *topLayout= new QHBoxLayout;
	topLayout->addWidget(calculateText);

	QHBoxLayout *buttonRow0 = new QHBoxLayout;
	buttonRow0->addWidget(openParenthesesButton);
	buttonRow0->addWidget(zeroButton);
	buttonRow0->addWidget(closeParenthesesButton);


	QHBoxLayout *buttonRow1 = new QHBoxLayout;
	buttonRow1->addWidget(oneButton);
	buttonRow1->addWidget(twoButton);
	buttonRow1->addWidget(threeButton);

	QHBoxLayout *buttonRow2 = new QHBoxLayout;
	buttonRow2->addWidget(fourButton);
	buttonRow2->addWidget(fiveButton);
	buttonRow2->addWidget(sixButton);

	QHBoxLayout *buttonRow3 = new QHBoxLayout;
	buttonRow3->addWidget(sevenButton);
	buttonRow3->addWidget(eightButton);
	buttonRow3->addWidget(nineButton);

	QHBoxLayout *bottomLayout = new QHBoxLayout;
	bottomLayout->addWidget(calculateButton);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLayout);
	leftLayout->addLayout(buttonRow3);
	leftLayout->addLayout(buttonRow2);
	leftLayout->addLayout(buttonRow1);
	leftLayout->addLayout(buttonRow0);
	leftLayout->addLayout(bottomLayout);

	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(addButton);
	rightLayout->addWidget(subtractButton);
	rightLayout->addWidget(multiplyButton);
	rightLayout->addWidget(divideButton);
	rightLayout->addWidget(exponentButton);
	rightLayout->addWidget(periodButton);
	rightLayout->addWidget(clearButton);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);


	setLayout(mainLayout);

}


void SimpleCalculator::calculate(){
	
	std::string calcLine = "";
	double result = 0.0;

	calcLine = calculateText->text().toStdString();
	
	if (calculateExpression(calcLine, &result) == true){
		calculateText->setText(QString::number(result));
		prevAnsInBox = true;

	}else{
		calculateText->setText(tr("ERROR"));
		prevAnsInBox = false;
	}

	

}

void SimpleCalculator::periodButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + ".");
}


void SimpleCalculator::zeroButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "0");
}

void SimpleCalculator::oneButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "1");
}

void SimpleCalculator::twoButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "2");
}

void SimpleCalculator::threeButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "3");
}

void SimpleCalculator::fourButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "4");
}

void SimpleCalculator::fiveButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "5");
}

void SimpleCalculator::sixButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "6");
}

void SimpleCalculator::sevenButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "7");
}

void SimpleCalculator::eightButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "8");
}

void SimpleCalculator::nineButtonClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "9");
}

void SimpleCalculator::addButtonClicked(){
	this->clearError();
	prevAnsInBox = false;
	calculateText->setText(calculateText->text() + "+");
}

void SimpleCalculator::subtractButtonClicked(){
	this->clearError();
	prevAnsInBox = false;
	calculateText->setText(calculateText->text() + "-");
}

void SimpleCalculator::multiplyButtonClicked(){
	this->clearError();
	prevAnsInBox = false;
	calculateText->setText(calculateText->text() + "*");
}

void SimpleCalculator::divideButtonClicked(){
	this->clearError();
	prevAnsInBox = false;
	calculateText->setText(calculateText->text() + "/");
}

void SimpleCalculator::openParenthesesClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + "(");
}

void SimpleCalculator::closeParenthesesClicked(){
	this->clearError();
	this->clearPrevAns();
	calculateText->setText(calculateText->text() + ")");
}

void SimpleCalculator::exponentButtonClicked(){
	this->clearError();
	prevAnsInBox = false;
	calculateText->setText(calculateText->text() + "^");
}

void SimpleCalculator::clear(){
	calculateText->setText("");
}


void SimpleCalculator::clearError(){
	if (QString::compare(calculateText->text(), "ERROR", Qt::CaseInsensitive) == 0){
		this->clear();
	}
	
}

void SimpleCalculator::clearPrevAns(){
	if (prevAnsInBox){
		this->clear();
	}
	prevAnsInBox = false;
}

