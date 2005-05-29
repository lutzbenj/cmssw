/*
 *  eventsetup_get_check_compile_time_error_t.cc
 *  EDMProto
 *
 *  Created by Chris Jones on 3/25/05.
 *
 */


#include "FWCore/CoreFramework/interface/EventSetup.h"
#include "FWCore/CoreFramework/interface/EventSetupProvider.h"
#include "FWCore/CoreFramework/interface/Timestamp.h"

using namespace edm;
class NotAGoodRecord {};

int main() {
   eventsetup::EventSetupProvider provider;
   EventSetup const& eventSetup = provider.eventSetupForInstance( Timestamp(0) );
   //This should cause a compile time failure since NotAGoodRecord
   /// does not inherit from edm::eventsetup::EventSetupRecord
   eventSetup.get<NotAGoodRecord>();
   
   return 0;
}
