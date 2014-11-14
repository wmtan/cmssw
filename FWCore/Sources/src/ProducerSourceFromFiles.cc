#include "FWCore/Sources/interface/ProducerSourceFromFiles.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"

namespace edm {
  ProducerSourceFromFiles::ProducerSourceFromFiles(ParameterSet const& pset, InputSourceDescription const& desc, bool realData, EventAuxiliary::ExperimentType eType) :
    ProducerSourceBase(pset, desc, realData, eType),
    FromFiles(pset) {
  }

  ProducerSourceFromFiles::~ProducerSourceFromFiles() {}

  void
  ProducerSourceFromFiles::fillDescription(ParameterSetDescription & desc) {
    ProducerSourceBase::fillDescription(desc);
    FromFiles::fillDescription(desc);
  }
}

