#ifndef WLGDPSTime_h
#define WLGDPSTime_h 1

#include <map>
#include "G4THitsMap.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4TrackLogger.hh"

////////////////////////////////////////////////////////////////////////////////
// Description:
//   This is a primitive scorer class for scoring global track time
//
///////////////////////////////////////////////////////////////////////////////

class WLGDPSTime : public G4VPrimitiveScorer
{
public:                                        // with description
  WLGDPSTime(G4String name, G4int depth = 0);  // default unit
  WLGDPSTime(G4String name, const G4String& unit, G4int depth = 0);
  virtual ~WLGDPSTime();

protected:  // with description
  virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*);

public:
  virtual void Initialize(G4HCofThisEvent*);
  virtual void EndOfEvent(G4HCofThisEvent*);
  virtual void clear();
  virtual void DrawAll();
  virtual void PrintAll();

  virtual void SetUnit(const G4String& unit);

private:
  G4int                          HCID;
  G4THitsMap<G4double>*          EvtMap;
  std::map<G4int, G4TrackLogger> fCellTrackLogger;
};
#endif
