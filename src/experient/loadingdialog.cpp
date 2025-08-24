#include "loadingdialog.h"
#include "ui_loadingdialog.h"

LoadingDialog::LoadingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingDialog)
{
    ui->setupUi(this);
    this->resize(10, 10);

        // 使用 GIF 文件路径
        QMovie *movie = new QMovie("C:/Users/LEGION/Desktop/pictrue02.gif");

        ui->movieLabel->setFixedSize(150, 150);
        ui->movieLabel->setScaledContents(true);
        ui->movieLabel->setMovie(movie);
        movie->start();

        setWindowModality(Qt::ApplicationModal); // 模态对话框
        setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog); // 去掉标题栏
}

LoadingDialog::~LoadingDialog()
{
    delete ui;
}
