#include "output.h"

#include "fluid.h"
#include "particle.h"
#include <cstdlib>
#include <iostream>


Output::Output(const std::string& filename) : file_(filename.c_str())
{
  if (file_.good())
  {
    // Matlab-style comment (to ease import) on first line
    file_ << "% t\tp[0].x\tp[0].y\tp[1].x\tp[1].y\t..." << std::endl;
  }
  else
  {
    std::cerr << "### Output file creation failed ###" << std::endl;
    std::cerr << "Make sure that '" << filename 
      << "' is writable." << std::endl;
    std::cerr << "The output directory must exist." << std::endl;
    exit(0);
  }
}

void Output::write(double t, const Fluid& fluid)
{
  const int nparticles = fluid.getNParticles();
  Fluid::ParticleArray particles = fluid.getParticles();

  file_ << t;
  for (size_t i = 0; i < nparticles; ++i)
  {
    const Properties props = particles[i]->getOldProperties();
    file_ << '\t' << props.x << '\t' << props.y;
  }
  file_ << std::endl;
}
