#ifndef STANDARD_CALCULATOR_H
#define STANDARD_CALCULATOR_H

#include <QObject>

class Standard_Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Standard_Calculator(QObject *parent = nullptr);

signals:
};

#endif // STANDARD_CALCULATOR_H
