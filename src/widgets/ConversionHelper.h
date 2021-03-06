#ifndef DISPAR_CONVERSION_HELPER_H
#define DISPAR_CONVERSION_HELPER_H

#include <QDialog>
#include <QList>

class QLineEdit;
class QTextEdit;
class QComboBox;

class ConversionHelper : public QDialog {
  Q_OBJECT

public:
  ConversionHelper(QWidget *parent = nullptr);

private slots:
  void onTextEdited(const QString &text);
  void onHexToText();
  void onTextToHex();

private:
  void createLayout();

  QList<QLineEdit *> edits;
  QTextEdit *hexEdit, *textEdit;
  QComboBox *encBox;
};

#endif // DISPAR_CONVERSION_HELPER_H
