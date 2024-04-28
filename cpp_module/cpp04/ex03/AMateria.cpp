
#include "AMateria.hpp"

// protected :
// 	std::string type;
// public :
// 	AMateria();
// 	~AMateria();
// 	AMateria(const AMateria& obj);
// 	AMateria& operator=(const AMateria& obj);
// 	AMateria(std::string const & type);
// 	std::string const& getType() const;
// 	virtual AMateria* clone() const = 0;
// 	virtual void use(ICharacter& target);

AMateria::AMateria(){}
AMateria::AMateria(const AMateria& obj){}
AMateria::AMateria(std::string const& type){}
std::string const& AMateria::getType() const{}
AMateria& AMateria::operator=(const AMateria& obj){}
AMateria::~AMateria(){}
