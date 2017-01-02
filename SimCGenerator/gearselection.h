#ifndef GEARSELECTION_H
#define GEARSELECTION_H

#include <QWidget>

#include <dialog.h>
#include <innards.h>


class Dialog;

namespace Ui {
class GearSelection;
}

class GearSelection : public QWidget
{
    Q_OBJECT

public:
    explicit GearSelection(QWidget *parent = 0);
    ~GearSelection();
    void Init(Dialog *dia);

    Dialog *d;

private:
    Ui::GearSelection *ui;

private slots:
    void MakeGear();
};

#endif // GEARSELECTION_H
