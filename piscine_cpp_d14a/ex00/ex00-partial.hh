#ifndef CLUEDO_H_
#define CLUEDO_H_

namespace Cluedo
{
  //Cards---------------------------------------------------------------------------
  class Card {
  protected:
    Card();
    ~Card();
    
  public:
    bool	IsPartOfTheCrime() const;
    
  protected:
    bool	_isPartOfTheCrime;
  };

  //Weapons---------------------------------------------------------------------------
  class Weapon : public Card {
  public:
    enum Name {
      Corde,
      Matraque,
      Poignard,
      Cle_Anglaise,
      Chandelier,
      Revolver
    };
    static const Name PartOfTheCrime;
    
  public:
    Weapon::Name	_name;
    bool		_fingerprint;

  public:
    Weapon(Weapon::Name name, bool bearsFingerprints);
    ~Weapon();

    bool	BearsFingerprints() const;
  };

  //Suspects---------------------------------------------------------------------------
  class Suspect : public Card {
  public:
    enum Name {
      Mlle_Rose,
      Pr_Violet,
      Col_Moutarde,
      Dr_Olive,
      Mme_Leblanc,
      Mme_Pervenche
    };
    static const Name PartOfTheCrime;

  public:
    Suspect::Name	_name;
    bool		_lying;

  public:
    Suspect(Suspect::Name name, bool isLying);
    ~Suspect();
    
    bool	IsLying() const;
  };

  //Rooms---------------------------------------------------------------------------
  class Room : public Card {
  public:
    enum Name {
      Cuisine,
      Grand_Salon,
      Veranda,
      Petit_Salon,
      Salle_a_Manger,
      Billard,
      Bibliotheque,
      Bureau,
      Hall
    };
    static const Name PartOfTheCrime;

  public:
    Room::Name		_name;
    bool		_passage;
    
  public:
    Room(Room::Name name, bool hasSecretPassage);
    ~Room();
    
    bool	HasSecretPassage() const;
  };
  //Game---------------------------------------------------------------------------
  class Game {
  public:
    static bool CaseSolved(Weapon* w[], Suspect* s[], Room* r[]);
  };

  //Exceptions---------------------------------------------------------------
  class WeaponException {
  private:
    std::string		_message;
    
  public:
    WeaponException();
    std::string const&	getMessage() const;
    Weapon	**getCards() const;
  };
  class SuspectException {
  private:
    std::string		_message;
  public:
    std::string const&	getMessage() const;
    Suspect	**getCards() const;
  };
  class RoomException {
  private:
    std::string		_message;
  public:
    std::string const&	getMessage() const;
    Room	**getCards() const;
  };
}

#endif // CLUEDO_H_
