/*
 *  eventsetup_dataget_check_compile_time_error_t.cc
 *  EDMProto
 *
 *  Created by Chris Jones on 4/7/05.
 *
 */

#include "FWCore/CoreFramework/interface/EventSetup.h"
#include "FWCore/CoreFramework/interface/EventSetupProvider.h"
#include "FWCore/CoreFramework/interface/Timestamp.h"
#include "FWCore/CoreFramework/interface/ESHandle.h"

using namespace edm;
class DataWithNoDefaultRecord {};

int main() {
   eventsetup::EventSetupProvider provider;
   EventSetup const& eventSetup = provider.eventSetupForInstance( Timestamp(0) );
   //This should cause a compile time failure since DataWithNoDefaultRecord
   /// does not have a default record assigned
   ESHandle<DataWithNoDefaultRecord> pData;
   eventSetup.getData(pData);
   
   return 0;
}
