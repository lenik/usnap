


/** <xmm:mapping href="getopt.xml" digest="2005-1-1"> */
  binding = {
      'name', &opt_name, CLP_STRING | CLP_OPTIONAL,
      'age',  &opt_age,  CLP_INT,
  };
/** </xmm:mapping> **/

clp_get_options(&binding);
ClpGetOptions getopt;
getopt->addArgument('name', ...);
