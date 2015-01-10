#ifndef CLUEDO_H_
#define CLUEDO_H_

namespace Cluedo
{
	class Card
	{
	public:
		enum Type
		{
			WEAPON,
			SUSPECT,
			ROOM
		};

	protected:
		Card(Card::Type cardType);
		~Card();

	public:
		bool	IsPartOfTheCrime() const;
		Type	CardType() const;

	protected:
		bool	_isPartOfTheCrime;

	private:
		Type	_cardType;
	};

	class Figurine
	{
	public:
		Figurine(bool isLost);
		~Figurine();

		bool	IsLost() const;
	};

	class Piece
	{
	public:
		Piece(int position);
		~Piece();

		int Position() const;
		void Position(int position);
	};

	class Weapon
	{
	public:
		enum Name
		{
			Corde,
			Matraque,
			Poignard,
			Cle_Anglaise,
			Chandelier,
			Revolver
		};
		static const Name PartOfTheCrime;

	public:
		Weapon(Weapon::Name name, bool bearsFingerprints, bool isLost);
		~Weapon();

		bool	BearsFingerprints() const;
	};

	class Suspect
	{
	public:
		enum Name
		{
			Mlle_Rose,
			Pr_Violet,
			Col_Moutarde,
			Dr_Olive,
			Mme_Leblanc,
			Mme_Pervenche
		};
		static const Name PartOfTheCrime;

	public:
		Suspect(Suspect::Name name, bool isLying);
		~Suspect();

		bool	IsLying() const;
	};

	class Room
	{
	public:
		enum Name
		{
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
		Room(Room::Name name, bool hasSecretPassage);
		~Room();

		bool	HasSecretPassage() const;
	};

	class Game
	{
	public:
		static bool CaseSolved(Weapon* w[], Suspect* s[], Room* r[]);
		static bool CaseSolved(Card* c[]);
	};
}

#endif // CLUEDO_H_
