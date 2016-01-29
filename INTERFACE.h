
#ifndef _INTERFACE_H_
#define _INTERFACE_H_



/**
 * File that defines the functions associated with the command interface
 * The valid commands are:
 *    - "cheque valor refe refb refc"
 *    - "processa"
 *	  - "porcessaR refc"
 *    - "infocheque ref"
 *    - "infocliente ref"
 *    - "info"
 *    - "sair"
 */

 #include <stdlib.h>
 #include "CHECK.h"
 #include "CLIENT.h"
 #include "QUEUE.h"
 #include "AUXILIARES.h"
 #include "AVL.h"

/**
 * Issues a new check to the database of checks yet to be processed.
 */
 void doCheck(char* command);

/**
 * Processes the oldest check in the database of checks and removes 
 * it from the database.
 * If the database is empty prints that information to the user.
 */
 void doProcess();

/**
 * Processes the check of reference refc and removes it from the database.
 * If it doesn't exist prints out that information to the user.
 */
 void doProcessR(char* command);

/**
 * Looks up the check with reference ref and prints out it's info
 */
 void doInfoCheck(char* command);

/**
 * Looks up for the client with reference ref and prints out it's info.
 */
 void doInfoCliente(char* command);

/**
 * Prints out the information of all the active clients with reference in 
 * a ascending order.
 */
 void doInfo();

/**
 * Exits the program and deletes everything, printing dome generic info.
 */
 void doExit();

#endif
