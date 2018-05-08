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

TrackerSD::TrackerSD(G4String name) : G4VSensitiveDetector(name)
{
  G4String HCname = "SDHC_";
  collectionName.insert(HCname);
  file.open("track.txt");
}


TrackerSD::~TrackerSD(){ }


void TrackerSD::Initialize(G4HCofThisEvent* HCE)
{
  trackerCollection = new TrackerHitsCollection(SensitiveDetectorName,collectionName[0]);
  static G4int HCID = -1;
  if(HCID<0)
  { HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); }
  HCE->AddHitsCollection( HCID, trackerCollection ); 
}


G4bool TrackerSD::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
  auto pos = aStep->GetPostStepPoint ()->GetPosition ();
  auto id =  aStep->GetTrack()->GetTrackID();
  G4cout << "ID:" << id << " " << pos.x () << " " << pos.y () << " " << pos.z () << G4endl;
  if(id == 1) file << pos.x () << " " << pos.y () << " " << pos.z () << std::endl;
  return true;
}


void TrackerSD::EndOfEvent(G4HCofThisEvent*)
{
  file.close ();
}


