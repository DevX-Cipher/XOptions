/* Copyright (c) 2020-2023 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef DIALOGVIEWCOLORS_H
#define DIALOGVIEWCOLORS_H

#include <QColorDialog>
#include <QDialog>
#include <QLineEdit>
#include <QToolButton>

#include "xoptions.h"

namespace Ui {
class DialogViewColors;
}

class DialogViewColors : public QDialog {
    Q_OBJECT

    enum COLUMN {
        COLUMN_TEXT_COLOR,
        COLUMN_TEXT_COLOR_REMOVE,
        COLUMN_BACKGROUND_COLOR,
        COLUMN_BACKGROUND_COLOR_REMOVE,
        COLUMN_GROUP,
        COLUMN_STRING
    };

public:
    struct RECORD {
        QString sGroup;
        QString sText;
        XOptions::ID id;
    };
    explicit DialogViewColors(QWidget *pParent = nullptr);
    ~DialogViewColors();

    void setOptions(XOptions *pOptions, const QList<RECORD> &listRecords, const QString &sTitle);
    void save();

private slots:
    void on_pushButtonCancel_clicked();
    void addRecord(qint32 nRow, const QString &sGroup, const QString &sText, XOptions::ID id);
    void addRecord(qint32 nRow, const RECORD &record);
    void updateRow(qint32 nRow);
    void on_pushButtonOK_clicked();
    void pushButtonSlot();

private:
    Ui::DialogViewColors *ui;
    XOptions *g_pOptions;
    QMap<XOptions::ID, QString> g_mapColors;
};

#endif  // DIALOGVIEWCOLORS_H
