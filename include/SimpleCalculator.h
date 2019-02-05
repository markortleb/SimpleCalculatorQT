#ifndef SIMPLECALCULATOR_H
#define SIMPLECALCULATOR_H

#include <QDialog>
#include <QString>

class QPushButton;
class QLineEdit;

class SimpleCalculator : public QDialog
{
	Q_OBJECT

public:
	explicit SimpleCalculator(QWidget *parent = 0);
	virtual ~SimpleCalculator() {};
	bool prevAnsInBox;


private slots:
	void calculate();
	void clear();
	void periodButtonClicked();
	void zeroButtonClicked();
	void oneButtonClicked();
	void twoButtonClicked();
	void threeButtonClicked();
	void fourButtonClicked();
	void fiveButtonClicked();
	void sixButtonClicked();
	void sevenButtonClicked();
	void eightButtonClicked();
	void nineButtonClicked();
	void multiplyButtonClicked();
	void addButtonClicked();
	void subtractButtonClicked();
	void divideButtonClicked();
	void openParenthesesClicked();
	void closeParenthesesClicked();
	void exponentButtonClicked();

private:
	void clearError();
	void clearPrevAns();
	QLineEdit *calculateText;
	QPushButton *periodButton;
	QPushButton *zeroButton;
	QPushButton *oneButton;
	QPushButton *twoButton;
	QPushButton *threeButton;
	QPushButton *fourButton;
	QPushButton *fiveButton;
	QPushButton *sixButton;
	QPushButton *sevenButton;
	QPushButton *eightButton;
	QPushButton *nineButton;
	QPushButton *addButton;
	QPushButton *subtractButton;
	QPushButton *multiplyButton;
	QPushButton *divideButton;
	QPushButton *calculateButton;
	QPushButton *clearButton;
	QPushButton *openParenthesesButton;
	QPushButton *closeParenthesesButton;
	QPushButton *exponentButton;


};

#endif //SIMPLECALCULATOR_H

