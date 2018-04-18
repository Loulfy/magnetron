// *************************************
// * TrackerSD.hh                      *
// *                                   *
// * Marine RUFFENACH                  *
// * ONERA-ERS (Toulouse)              *
// * marine.ruffenach@onera.fr         *
// *                                   *
// * Date 09/04/2018                   *
// *************************************

#ifndef TrackerSD_h
#define TrackerSD_h 1

#include "TrackerHit.hh"
#include "G4VSensitiveDetector.hh"

class G4Step;
class G4HCofThisEvent;

class TrackerSD : public G4VSensitiveDetector
{
public:
    TrackerSD(G4String);
    ~TrackerSD();

    void Initialize(G4HCofThisEvent*);
    G4bool ProcessHits(G4Step*, G4TouchableHistory*);
    void EndOfEvent(G4HCofThisEvent*);
    void Clear();

private:
    TrackerHitsCollection* trackerCollection;
};

#endif
