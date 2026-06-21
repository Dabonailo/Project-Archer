#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, bool d, float e, int _id)
			: Entidade(pos, tam, textura, v, e, _id), danoso(d)
		{
			//body.setFillColor(sf::Color::Yellow);
		}

		Obstaculo::~Obstaculo()
		{
		}

		void Obstaculo::salvarDataBuffer()
		{
			Entidade::salvarDataBuffer();

			buffer
				<< danoso << ' ';
		}

		void Obstaculo::carregar(std::istream& in)
		{
			Entidade::carregar(in);

			in >> danoso;
		}
	}
}