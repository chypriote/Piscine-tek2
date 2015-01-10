#ifndef		WARPSYSTEM_H_
#define		WARPSYSTEM_H_

namespace {
  class QuantumReactor;
  class Core;
}

namespace WarpSystem {
  class QuantumReactor {
  private:
    bool _stability;
  
  public:
    QuantumReactor();
    ~QuantumReactor();
    
    void setStability(bool stability);
    bool getStability();
    bool isStable();
  };
  
  class Core {
  private:
    QuantumReactor *_coreReactor;
    
  public:
    Core(QuantumReactor *coreReactor);
    ~Core();
    
    bool getStability();
    QuantumReactor *getQuantumReactor();
    QuantumReactor *checkReactor();
    bool isStable();
  };
}

#endif
