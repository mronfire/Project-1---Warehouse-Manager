/*************************************************************************//**
 * Authors  : Max Nelson, Mario Rodriguez, Trenton Coggeshall, Arturo Salgado
 * Class    : Computer Science 1C
 * Period   : Tuesday - Thursday 1130am to 220pm
 * Due Date : 10/20/2016
 ****************************************************************************/
#ifndef FILEPARSING_H
#define FILEPARSING_H

#include "header.h"
#include "purchase.h"
#include "sales.h"
#include "member.h"

//! Create member list function
/*!
 * \brief This function will create the linked list of members
 * \param inFile
 * \return the top of member list
 */
member *CreateMemberList(QString inFile);

//! Create day list function
/*!
 * \brief This function will create the linked list for the days
 * \param numDays
 * \param day1
 * \return the top of days list
 */
SalesDay *CreateDayList(int numDays, QString day1);

//! Read all purchases
/*!
 * \brief This function will read all purchases from each day and assign it to
 *        respective member and the day it was bought
 * \param inFile
 * \param memberList
 * \param dayList
 */
void ReadPurchases(QString inFile, member *memberList, SalesDay *dayList);

//! Delete all members
/*!
 * \brief This function will delete all members of the list
 * \param memberList
 */
void DeleteMembers(member *memberList);

//! Delete all days
/*!
 * \brief This function will delete all days of the list
 * \param dayList
 */
void DeleteDays(SalesDay *dayList);

//! Save all data
/*!
 * \brief This function will save all data made to the files for later use
 * \param memFileName
 * \param purchFileName
 * \param memberList
 * \param dayList
 */
void SaveData(QString memFileName, QString purchFileName, member *memberList, SalesDay *dayList);

#endif // FILEPARSING_H
