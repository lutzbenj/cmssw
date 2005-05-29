
/*----------------------------------------------------------------------
$Id: FilterWorker.cc,v 1.2 2005/04/05 16:24:12 paterno Exp $
----------------------------------------------------------------------*/
#include <memory>

#include "FWCore/CoreFramework/src/FilterWorker.h"

#include "FWCore/CoreFramework/interface/EventPrincipal.h"
#include "FWCore/CoreFramework/interface/Event.h"
#include "FWCore/CoreFramework/interface/EDFilter.h"
#include "FWCore/CoreFramework/interface/Provenance.h"


namespace edm
{
  FilterWorker::FilterWorker(std::auto_ptr<EDFilter> ed,
			     const ModuleDescription& md):
   md_(md),
   filter_(ed)
  {
  }

  FilterWorker::~FilterWorker()
  {
  }

  bool 
  FilterWorker::doWork(EventPrincipal& ep, EventSetup const& c)
  {
    Event e(ep,md_);
    return filter_->filter(e, c);
    // a filter cannot write into the event, so commit is not needed
    // although we do know about what it asked for
  }
}
