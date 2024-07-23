#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // When enlarge or reduce the screen, plainText also enlarges and shrinks.
    this->setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->clear();
    ui->statusbar->showMessage("New file opened!");
}


void MainWindow::on_actionOpen_triggered()
{
    QString filePath =QFileDialog::getOpenFileName(this, "New file opened!");
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)){   // The file was opened in ReadOnly mode.
        // If the file created cannot be opened, write the error message.
        QMessageBox::critical(this, "Mistake", file.errorString());
        return;
    }
    // stream is an object used to read and write data from a file.
    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();
    // The path of opened file is shown in status bar.
    ui->statusbar->showMessage(filePath);
}


void MainWindow::on_actionSave_triggered()
{
    QString filePath=QFileDialog::getSaveFileName(this, "Save File!");
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly)){  // WriteOnly mode.
        QMessageBox::critical(this, "Mistake", file.errorString());
        return;
    }
    // stream is an object used to read and write data from a file.
    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();
    // The path of the opened file is shown in the status bar.
    ui->statusbar->showMessage(filePath);
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void MainWindow::on_actionC_triggered()
{
    ui->plainTextEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}


void MainWindow::on_actionSelect_All_triggered()
{
    ui->plainTextEdit->selectAll();
}


void MainWindow::on_actionSelect_None_triggered()
{
    //  cursor
    //  QTextCursor cursor = ui->plainTextEdit->textCursor();
    //  cursor.movePosition(QTextCursor::End);
    //  ui->plainTextEdit->setTextCursor(cursor);
    //  ui->plainTextEdit->moveCursor(QTextCursor::End);
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    int position = cursor.position();
    cursor.clearSelection();
    cursor.setPosition(position, QTextCursor::MoveMode::KeepAnchor);
    ui->plainTextEdit->setTextCursor(cursor);
    //  the place where the cursor left off.
}


void MainWindow::on_actionToolbar_Top_triggered()
{
    addToolBar(Qt::TopToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Bottom_triggered()
{
    addToolBar(Qt::BottomToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Right_triggered()
{
    addToolBar(Qt::RightToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Left_triggered()
{
    addToolBar(Qt::LeftToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Floatable_triggered()
{
    // toolBar does not appear outside of plainText.
    ui->toolBar->setFloatable(false);
}


void MainWindow::on_actionToolbar_Movable_triggered()
{
    // fixes the location of the toolBar.
    ui->toolBar->setMovable(false);
}


void MainWindow::on_actionOpen_Form_triggered()
{
    MainWindow2 *SecondScreen = new MainWindow2(this);
    SecondScreen->show();
}

