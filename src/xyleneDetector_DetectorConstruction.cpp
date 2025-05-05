#include "xyleneDetector_DetectorConstruction.h"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "xyleneDetector_SensitiveDetector.h"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"


xyleneDetector_DetectorConstruction::xyleneDetector_DetectorConstruction() {}

xyleneDetector_DetectorConstruction::~xyleneDetector_DetectorConstruction() {}

G4VPhysicalVolume* xyleneDetector_DetectorConstruction::Construct() {
     
    // ----------------Required Materials----------------------------------

    G4NistManager* nist = G4NistManager::Instance();
    // Air
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    // Aluminum
    G4Material* aluminum = nist->FindOrBuildMaterial("G4_Al");
    // Glass (SiO2)
    G4Material* glass = nist->FindOrBuildMaterial("G4_SILICON_DIOXIDE");
    // Xylene (C8H10)
    G4Element* C = new G4Element("Carbon", "C", 6, 12.011 * g/mole);
    G4Element* H = new G4Element("Hydrogen", "H", 1, 1.008 * g/mole);
    G4Material* xylene = new G4Material("Xylene", 0.87 * g/cm3, 2);
    xylene->AddElement(C, 8);
    xylene->AddElement(H, 10);


    //----------------Geometry---------------------------------------------------

    // 1. World Construction (1m x 1m x 1m box)

    G4double worldSize = 1.0 * m;
    G4Box* solidWorld = new G4Box("World", worldSize/2, worldSize/2, worldSize/2);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0);
    //G4PVPlacement(G4RotationMatrix* pRot, const G4ThreeVector& tlate, G4LogicalVolume* pCurrentLogical, const G4String& pName, G4LogicalVolume* pMotherLogical, G4bool pMany, G4int pCopyNo);
    
    // 2. Aluminum Cylinder (hollow tube: 5inch outer diameter, 2inch height, 3mm thick side walls)
    
    G4double outerRadius = 12.7 / 2 * cm; // 5 inches
    G4double thickness = 0.3 * cm;        // 3 mm
    G4double innerRadius = outerRadius - thickness; // 12.1 cm diameter
    G4double outerHeight = 5.08 * cm;     // 2 inches
    G4Tubs* solidCylinderWalls = new G4Tubs("CylinderWalls", innerRadius, outerRadius, outerHeight/2, 0, 360*deg);
    G4LogicalVolume* logicCylinderWalls = new G4LogicalVolume(solidCylinderWalls, aluminum, "CylinderWalls");
    // Set aluminum color (silver/gray)
    G4VisAttributes* aluminumVisAtt = new G4VisAttributes(G4Colour(0.7, 0.7, 0.7, 1.0)); // RGB: gray, opaque
    logicCylinderWalls->SetVisAttributes(aluminumVisAtt);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logicCylinderWalls, "CylinderWalls", logicWorld, false, 0, true);
    // Aluminum Bottom (3mm thick, outer radius)
    G4Tubs* solidBottom = new G4Tubs("Bottom", 0, outerRadius, thickness/2, 0, 360*deg);
    G4LogicalVolume* logicBottom = new G4LogicalVolume(solidBottom, aluminum, "Bottom");
    logicBottom->SetVisAttributes(aluminumVisAtt);
    new G4PVPlacement(0, G4ThreeVector(0, 0, -outerHeight/2 - thickness/2), logicBottom, "Bottom", logicWorld, false, 0, true);

    // 3.  Inner volume for xylene (inner: 12.1cm diameter, 4.78cm height due to bottom)
    G4double innerHeight = outerHeight - thickness; // 4.78 cm
    G4Tubs* solidXylene = new G4Tubs("Xylene", 0, innerRadius, innerHeight/2, 0, 360*deg);
    G4LogicalVolume* logicXylene = new G4LogicalVolume(solidXylene, xylene, "Xylene");
    // Set xylene color (yellow, slightly transparent)
    G4VisAttributes* xyleneVisAtt = new G4VisAttributes(G4Colour(1.0, 1.0, 0.0, 0.8)); // RGB: yellow, 80% opaque
    logicXylene->SetVisAttributes(xyleneVisAtt);
    new G4PVPlacement(0, G4ThreeVector(0, 0, -outerHeight/2 + innerHeight/2), logicXylene, "Xylene", logicWorld, false, 0, true);

    // 4. Glass Window (1mm thick, same diameter as inner volume)
    G4double glassThickness = 0.1 * cm; // 1mm
    G4Tubs* solidGlass = new G4Tubs("Glass", 0, innerRadius, glassThickness/2, 0, 360*deg);
    G4LogicalVolume* logicGlass = new G4LogicalVolume(solidGlass, glass, "Glass");
        // Set glass color (light blue, transparent)
    G4VisAttributes* glassVisAtt = new G4VisAttributes(G4Colour(0.0, 0.5, 1.0, 0.2)); // RGB: light blue, 20% opaque
    glassVisAtt->SetForceSolid(true); // Ensures glass is drawn as a solid surface
    logicGlass->SetVisAttributes(glassVisAtt);
    //new G4PVPlacement(0, G4ThreeVector(0, 0, outerHeight/2 - glassThickness/2), logicGlass, "Glass", logicWorld, false, 0, true);
    new G4PVPlacement(0, G4ThreeVector(0, 0, outerHeight/2 + glassThickness/2), logicGlass, "Glass", logicWorld, false, 0, true);
    // Logic to Attach sensitive detector to a logical volume
    // Uncomment and adjust as needed, e.g., attach to glass or xylene
    // neutronDetector_SensitiveDetector* detector = new neutronDetector_SensitiveDetector("SensitiveDetector");
    // G4SDManager::GetSDMpointer()->AddNewDetector(detector);
    // logicXylene->SetSensitiveDetector(detector); // Example: attach to xylene
    return physWorld;
}
