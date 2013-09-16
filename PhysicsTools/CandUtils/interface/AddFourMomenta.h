#ifndef CandUtils_AddFourMomenta_h
#define CandUtils_AddFourMomenta_h
/** \class AddFourMomenta
 *
 * set up a composite reco::Candidate adding its 
 * daughters four-momenta and electric charge
 *
 * \author Luca Lista, INFN
 *
 *
 *
 */
#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "FWCore/ParameterSet/interface/ParameterSetfwd.h"

struct AddFourMomenta {
  /// default constructor
  AddFourMomenta() { }
  /// constructor
  explicit AddFourMomenta( const edm::ParameterSet & ) { }
  /// set up a candidate
  void set( reco::Candidate& c ) const;
};

#endif
