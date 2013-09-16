//-------------------------------------------------
//
/** \class L1MuGMTMIAUEtaProLUT
 *
 *   MIAUEtaPro look-up table
 *          
 *   this class was automatically generated by 
 *     L1MuGMTLUT::MakeSubClass()  
*/ 
//
//   Author :
//   H. Sakulin            HEPHY Vienna
//
//   Migrated to CMSSW:
//   I. Mikulec
//
//--------------------------------------------------
#ifndef L1TriggerGlobalMuonTrigger_L1MuGMTMIAUEtaProLUT_h
#define L1TriggerGlobalMuonTrigger_L1MuGMTMIAUEtaProLUT_h

//---------------
// C++ Headers --
//---------------


//----------------------
// Base Class Headers --
//----------------------
#include "L1Trigger/GlobalMuonTrigger/src/L1MuGMTLUT.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//              ---------------------
//              -- Class Interface --
//              ---------------------


class L1MuGMTMIAUEtaProLUT : public L1MuGMTLUT {
  
 public:
  enum {MIP_DT, MIP_BRPC, ISO_DT, ISO_BRPC, MIP_CSC, MIP_FRPC, ISO_CSC, ISO_FRPC};

  /// constuctor using function-lookup
  L1MuGMTMIAUEtaProLUT() : L1MuGMTLUT("MIAUEtaPro", 
				       "MIP_DT MIP_BRPC ISO_DT ISO_BRPC MIP_CSC MIP_FRPC ISO_CSC ISO_FRPC",
				       "eta(6) pt(5) charge(1)",
				       "eta_sel(10)", 12, false) {
    InitParameters();
  } ;

  /// destructor
  virtual ~L1MuGMTMIAUEtaProLUT() {};

  /// specific lookup function for eta_sel
  unsigned SpecificLookup_eta_sel (int idx, unsigned eta, unsigned pt, unsigned charge) const {
    std::vector<unsigned> addr(3);
    addr[0] = eta;
    addr[1] = pt;
    addr[2] = charge;
    return Lookup(idx, addr) [0];
  };

  /// specific lookup function for entire output field
  unsigned SpecificLookup (int idx, unsigned eta, unsigned pt, unsigned charge) const {
    std::vector<unsigned> addr(3);
    addr[0] = eta;
    addr[1] = pt;
    addr[2] = charge;
    return LookupPacked(idx, addr);
  };



  /// access to lookup function with packed input and output

  virtual unsigned LookupFunctionPacked (int idx, unsigned address) const {
    std::vector<unsigned> addr = u2vec(address, m_Inputs);
    return TheLookupFunction(idx ,addr[0] ,addr[1] ,addr[2]);

  };

 private:
  /// Initialize scales, configuration parameters, alignment constants, ...
  void InitParameters();

  /// The lookup function - here the functionality of the LUT is implemented
  unsigned TheLookupFunction (int idx, unsigned eta, unsigned pt, unsigned charge) const;

  /// Private data members (LUT parameters);
  int m_IsolationCellSizeEta;
  static float caloEtaBounds[15];
};
#endif



















