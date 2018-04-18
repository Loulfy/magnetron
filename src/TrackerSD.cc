// *************************************
// * TrackerSD.cc                      *
// *                                   *
// * Marine RUFFENACH                  *
// * ONERA-ERS (Toulouse)              *
// * marine.ruffenach@onera.fr         *
// *                                   *
// * Date 09/04/2018                   *
// *************************************

#include "TrackerSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

//.......................................

TrackerSD::TrackerSD(G4String name)
:G4VSensitiveDetector(name)
{
  G4String HCname = "SDHC_";
  collectionName.insert(HCname);
}


TrackerSD::~TrackerSD(){ }


void TrackerSD::Initialize(G4HCofThisEvent* HCE)
{
  trackerCollection = new TrackerHitsCollection
                          (SensitiveDetectorName,collectionName[0]); 
  static G4int HCID = -1;
  if(HCID<0)
  { HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); }
  HCE->AddHitsCollection( HCID, trackerCollection ); 
}


G4bool TrackerSD::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
  G4double edep = aStep->GetTotalEnergyDeposit();
  G4cout << "Deposited Energy : " << edep << G4endl;
  if(edep==0.) return false;

  TrackerHit* newHit = new TrackerHit();
  newHit->SetTrackID  (aStep->GetTrack()->GetTrackID());
  newHit->SetEdep     (edep);
  newHit->SetPos      (aStep->GetPostStepPoint()->GetPosition());
  trackerCollection->insert( newHit );

  return true;
}


void TrackerSD::EndOfEvent(G4HCofThisEvent*)
{

}


