#pragma once
#include <QMainWindow>
#include <QpushButton>

class InterfaceGraphique : public QMainWindow
{
	Q_OBJECT

public:
	InterfaceGraphique(QWidget* parent = nullptr);

	~InterfaceGraphique() noexcept;

private:
	QPushButton* boutonDebut = nullptr;
};
