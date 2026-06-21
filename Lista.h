#pragma once
#include "Entidade.h"

namespace Listas
{
	template<typename TL>
	class Lista
	{
	public:
		template<typename TE>
		class Elemento
		{
		private:
			Elemento<TE>* pProx;
			TE* pInfo;

		public:
			Elemento(TE* e = nullptr)
				: pProx(nullptr), pInfo(e) {
			}

			~Elemento() {}

			void setInfo(TE* p)
			{
				pInfo = p;
			}

			void setProximo(Elemento<TE>* pE)
			{
				pProx = pE;
			}

			Elemento<TE>* getProximo() const
			{
				return pProx;
			}

			TE* getInfo() const
			{
				return pInfo;
			}
		};

		template<class TE>
		class Iterator
		{
		private:
			Elemento<TE>* atual;

		public:
			Iterator(Elemento<TE>* c = nullptr)
				: atual(c)
			{
			}

			~Iterator() {}

			Iterator& operator++()
			{
				if (atual)
					atual = atual->getProximo();

				return *this;
			}

			Iterator operator++(int)
			{
				Iterator temp = *this;

				if (atual)
					atual = atual->getProximo();

				return temp;
			}

			bool operator==(const Iterator& outro) const
			{
				return atual == outro.atual;
			}

			bool operator!=(const Iterator& outro) const
			{
				return atual != outro.atual;
			}

			TE* operator*() const
			{
				if (atual)
					return atual->getInfo();

				return nullptr;
			}

			Elemento<TE>* getAtual() const
			{
				return atual;
			}
		};
	private:
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;

	public:
		Lista() :pPrimeiro(NULL), pUltimo(NULL) {}

		~Lista() { limpar(); }

	private:
		Lista(const Lista&) = delete;
		Lista& operator=(const Lista&) = delete;

	public:
		void incluirElemento(TL* p) {
			if (p) {
				Elemento<TL>* NovoElemento = new Elemento<TL>(p);

				if (pPrimeiro == NULL) {
					pPrimeiro = NovoElemento;
					pUltimo = NovoElemento;
				}

				else {
					pUltimo->setProximo(NovoElemento);
					pUltimo = NovoElemento;
				}
			}
		}

		void removerElemento(TL* e)
		{
			if (!pPrimeiro)
				return;

			Elemento<TL>* atual = pPrimeiro;
			Elemento<TL>* anterior = nullptr;

			while (atual)
			{
				if (atual->getInfo() == e)
				{
					if (anterior)
						anterior->setProximo(atual->getProximo());
					else
						pPrimeiro = atual->getProximo();

					if (atual == pUltimo)
						pUltimo = anterior;

					delete atual;
					return;
				}

				anterior = atual;
				atual = atual->getProximo();
			}
		}

		void limpar()
		{
			while (pPrimeiro)
			{
				Elemento<TL>* aux = pPrimeiro;
				pPrimeiro = pPrimeiro->getProximo();
				delete aux;
			}

			pPrimeiro = nullptr;
			pUltimo = nullptr;
		}

		Elemento<TL>* getPrimeiro() { return pPrimeiro; }

		int getTamanho() const
		{
			int count = 0;
			Elemento<TL>* atual = pPrimeiro;
			while (atual)
			{
				count++;
				atual = atual->getProximo();
			}
			return count;
		}
	};
}