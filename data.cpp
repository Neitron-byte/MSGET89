#include "data.h"
Data* Data::pData = nullptr;
int Data::Count = 0;

void Data::print()
{
    if(!m_vectorRezultVal.isEmpty()){
    QAxObject* pword = new QAxObject("Word.Application");
    QAxObject* pdoc = pword->querySubObject("Documents");
    pdoc = pdoc->querySubObject("Add()");

    QAxObject* prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",0,100);
    prange->setProperty("Text",tr("Protocol verification"));
    QAxObject* pFont = prange->querySubObject("Font");
    pFont->setProperty("Size",18);
    pFont->setProperty("Name", "Courier New");

    QAxObject *alignment_range = prange->querySubObject("ParagraphFormat");
       alignment_range->setProperty("Alignment", "wdAlignParagraphCenter");
       alignment_range->setProperty("SpaceAfter", 0);

    prange->dynamicCall("InsertParagraphAfter()");
    prange->dynamicCall("InsertParagraphAfter()");
    pFont->setProperty("Size",14);
    prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",101,200);
    prange->setProperty("Text",tr("Time: ")+ QTime::currentTime().toString(Qt::SystemLocaleLongDate));

    alignment_range = prange->querySubObject("ParagraphFormat");
    alignment_range->setProperty("Alignment", "wdAlignParagraphLeft");
    alignment_range->setProperty("SpaceAfter", 0);


    prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",201,300);
    prange->setProperty("Text","              ");

    prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",301,400);
    prange->setProperty("Text",tr("Date: ")+QDate::currentDate().toString(Qt::SystemLocaleLongDate));

    prange->dynamicCall("InsertParagraphAfter()");
    prange->dynamicCall("InsertParagraphAfter()");

    prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",401,500);
    prange->setProperty("Text",tr("Temperature: ")+ QString::number(m_temp));

    prange->dynamicCall("InsertParagraphAfter()");
    prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",501,600);
    prange->setProperty("Text",tr("Full name: ")+ m_fullName);

    prange->dynamicCall("InsertParagraphAfter()");
    prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",601,700);
    prange->setProperty("Text",tr("Model: ")+ m_model);

    prange->dynamicCall("InsertParagraphAfter()");
    prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",701,800);
    prange->setProperty("Text",tr("Serial number: ")+ m_serialNum);

    prange->dynamicCall("InsertParagraphAfter()");
    prange = pdoc->querySubObject("Range()");
    prange->dynamicCall("SetRange(int,int)",801,900);
    prange->setProperty("Text",tr("Company: ")+ m_company);

    prange->dynamicCall("InsertParagraphAfter()");
    prange->dynamicCall("InsertParagraphAfter()");

    int start = 900;
    for (int i = 0; i < m_vectorRezultVal.size(); ++i) {
        qDebug() << m_vectorRezultVal.size();
        prange = pdoc->querySubObject("Range()");
        prange->dynamicCall("SetRange(int,int)",start+i+1,start+((i+1)*100));
        if(m_vectorTypeVer[i] == 0){
            prange->setProperty("Text",tr("DC-AC: ")+ QString::number(m_vectorRezultVal[i]));
        } else {
            prange->setProperty("Text",tr("AC-AC: %1 kHz").arg(m_vectorTypeVer[i])+ QString::number(m_vectorRezultVal[i]));
        }

        prange->dynamicCall("InsertParagraphAfter()");
    }

    pword->setProperty("Visible",true);

     }
}

Data::Data(QObject *parent) : QObject(parent)
{
    qDebug() << "Create Data";
}
