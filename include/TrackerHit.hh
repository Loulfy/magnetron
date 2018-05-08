// *************************************
// * TrackerHit.hh                     *
// *                                   *
// * Marine RUFFENACH                  *
// * ONERA-ERS (Toulouse)              *
// * marine.ruffenach@onera.fr         *
// *                                   *
// * Date 09/04/2018                   *
// *************************************

#ifndef TrackerHit_h
#define TrackerHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class TrackerHit : public G4VHit
{
public:

    TrackerHit();
    ~TrackerHit();

    TrackerHit(const TrackerHit&);

    const TrackerHit& operator=(const TrackerHit&);
    int operator==(const TrackerHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);

public:

// $$G4DFLIB$$ //
    void SetPDGEncoding		(G4int pdgencoding)	{ PDGEncoding = pdgencoding;	};
// $$G4DFLIB$$ //
	void SetParentID		(G4int parent)      { ParentID = parent;			};
    void SetTrackID			(G4int track)       { trackID = track;				};
    void SetParticleType	(G4String nameT)	{ ParticleType = nameT;			};
    void SetParticleName	(G4String name)		{ ParticleName = name;			};
    void SetVolumeName		(G4String nameV)	{ VolumeName = nameV;			};
    void SetZ   			(G4int z)        	{ Z = z; 						};
    void SetA   			(G4int a)        	{ A = a; 						};
    void SetVertexKineticEnergy	(G4double VQ)	{ VertexKineticEnergy = VQ; 	};
    void SetVertexPos(G4ThreeVector xyz) { VertexPos = xyz; 					};
    void SetVertexMomentum(G4ThreeVector xyz) { VertexMomentum = xyz; 					};
    void SetKineticEnergy (G4double Q)			{ KineticEnergy = Q; 			};
    void SetPostStepKineticEnergy (G4double Q)	{ PostStepKineticEnergy = Q; 	};
    void SetPx      		(G4double px)       { Px = px; 						};
    void SetPy      		(G4double py)       { Py = py; 						};
    void SetPz      		(G4double pz)       { Pz = pz; 						};
    void SetEdep      		(G4double de)       { Edep = de; 					};
    void SetStepLength		(G4double length)   { StepLength = length;			};
    void SetPos       		(G4ThreeVector xyz) { Pos = xyz; 					};
    void SetMomentum		(G4ThreeVector xyz) { Momentum = xyz; 				};
		
// $$G4DFLIB$$ //
    G4int			GetPDGEncoding ()		{ return PDGEncoding; 			};
// $$G4DFLIB$$ //
	G4int			GetParentID ()			{ return ParentID; 			};
    G4int			GetTrackID ()			{ return trackID; 			};
    G4String		GetParticleType ()		{ return ParticleType;	};
    G4String		GetParticleName ()		{ return ParticleName; };
    G4String		GetVolumeName ()		{ return VolumeName; };
    G4int			GetZ ()					{ return Z; };
    G4int			GetA ()      { return A; 						};
    G4double		GetVertexKineticEnergy (){ return VertexKineticEnergy; };
    G4ThreeVector GetVertexPos() { return VertexPos; 					};
    G4ThreeVector GetVertexMomentum() { return VertexMomentum ; 					};
    G4double		GetKineticEnergy ()      { return KineticEnergy; };
    G4double		GetPostStepKineticEnergy ()      { return PostStepKineticEnergy; };
    G4double		GetPx ()      { return Px; 						};
    G4double		GetPy ()      { return Py; 						};
    G4double		GetPz ()      { return Pz; 						};
    G4double		GetEdep ()      { return Edep; 					};
    G4ThreeVector	GetPos ()  		{ return Pos; 					};
	G4ThreeVector	GetMomentum ()  		{ return Momentum; 		  };
	G4double		GetStepLength ()			{ return StepLength; 		};
		
		
private:

// $$G4DFLIB$$ //
    G4int			PDGEncoding;
// $$G4DFLIB$$ //
	  G4int			ParentID;
    G4int			trackID;
    G4String		ParticleType;
    G4String		ParticleName;
    G4String		VolumeName;
    G4int			Z;
    G4int			A;
    G4double		VertexKineticEnergy;
    G4double		KineticEnergy;
    G4double		PostStepKineticEnergy;
    G4double		Px;
    G4double		Py;
    G4double		Pz;
    G4double		Edep;
    G4double		StepLength;
    G4ThreeVector	Pos;
    G4ThreeVector	VertexPos;
    G4ThreeVector	Momentum;
    G4ThreeVector	VertexMomentum;
    
};

typedef G4THitsCollection<TrackerHit> TrackerHitsCollection;

extern G4Allocator<TrackerHit> TrackerHitAllocator;

inline void* TrackerHit::operator new(size_t)
{
    //void *aHit;
    //aHit = (void *) TrackerHitAllocator.MallocSingle();
    //return aHit;
  return TrackerHitAllocator.MallocSingle();
}

inline void TrackerHit::operator delete(void *aHit)
{
    TrackerHitAllocator.FreeSingle(static_cast<TrackerHit*>(aHit));
}

#endif
