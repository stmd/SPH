#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <string>

struct Properties;
class Particle {
 public:
  Particle(int tag, int N, Properties& properties);
  ~Particle();

  // Return/Update particle properties
  // ID is either "OLD" or "NEW"
  int get(const std::string& ID, Properties& properties); 
  int set(const std::string& ID, Properties& properties);
  
  void addNeighbor(Particle* neighbor);        // Add a neighbor tag
  int numberOfNeighbors();                     // Return neighbors_
  void getNeighbors(int neighbors[]);          // Get neighborarray_
  int getTag();                                // Return tag_
  void deleteNeighbors();                      // Re-initialize neighborarray_
  
 private:
  double* x_;                     // Location Pointer
  double* v_;                     // Velocity Pointer
  double* xnew_;                  // New Location Pointer
  double* vnew_;                  // New Velocity Pointer
  double mass_;                   // Particle Mass
  double visc_;                   // Particle Viscosity
  double density_;                // Particle Density
  double densitynew_;             // Particle New Density
  double pressure_;               // Particle Pressure
  int tag_;                       // Particle identifier
  int neighbors_;                 // Number of neighbors
  int* neighborarray_;            // Array of neighbor tags
  int N_;                         // Global Number of Particles

  void initializeNeighborArray(); // Initialize neighbor array
};

#endif  // PARTICLE_H
