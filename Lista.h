#pragma once
#include "Entidade.h"

namespace Listas
{
	template<typename TL>
	class Lista
	{
	public:
		template<typename TE>
		class Elemento {
		private:
			Elemento<TE>* pProx;
			TE* pInfo;

		public:
			Elemento(TE* e) : pProx(NULL), pInfo(e) {}
			~Elemento() {}

			void incluir(TE* p) {
				pInfo = p;
			}

			void setProximo(Elemento<TE>* pE) {
				pProx = pE;
			}

			Elemento<TE>* getProximo() {
				return pProx;
			}

			TE* getInfo() {
				return pInfo;
			}
		};

		template <class TE>
		class Iterator
		{
		private:
			Elemento<TE>* atual;
		public:
			Iterator(Elemento<TE>* c = nullptr) :
				atual(c) {
			}
			~Iterator() {}

			Iterator& operator++()
			{
				atual = atual->prox;
				return *this;
			}
			Iterator& operator++(int)
			{
				atual = atual->get_Proximo();
				return *this;
			}
			bool operator==(const Elemento<TE>* outro) const
			{
				return atual == outro;
			}

			bool operator!=(const Elemento<TE>* outro) const
			{
				return !(atual == outro);
			}
			void operator=(const Elemento<TE>* outro)
			{
				atual = outro;
			}
			TE* operator*()
			{
				if (atual)
					return atual->get_data();
			}
			const Elemento<TE>* get_atual() const { return atual; }
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

		void removerElemento(TL* e) {
			if (pPrimeiro == NULL) {
				return;
			}
			else if (pPrimeiro->getInfo() == pUltimo->getInfo() && pPrimeiro->getInfo() == e) {
				delete pPrimeiro;
				pPrimeiro = NULL;
				pUltimo = NULL;
			}
			else if (pPrimeiro->getInfo() == e) {
				Elemento<TL>* aux = pPrimeiro->getProximo();
				delete pPrimeiro;
				pPrimeiro = aux;
			}
			else if (pUltimo->getInfo() == e) {
				Elemento<TL>* aux = pPrimeiro;
				while (aux->getProximo() != pUltimo) {
					aux = aux->getProximo();
				}
				delete pUltimo;
				aux->setProximo(NULL);
				pUltimo = aux;
			}
			else {
				Elemento<TL>* aux = pPrimeiro;
				while (aux->getProximo() && aux->getProximo()->getInfo() != e) {
					aux = aux->getProximo();
				}
				if (aux->getProximo()) {
					Elemento<TL>* temp = aux->getProximo();
					aux->setProximo(temp->getProximo());
					delete temp;
				}
			}
		}

		void limpar() {
			while (pPrimeiro) {
				Elemento<TL>* aux = pPrimeiro;
				pPrimeiro = pPrimeiro->getProximo();
				delete aux;
			}
			pUltimo = NULL;
		}

		Elemento<TL>* getPrimeiro() { return pPrimeiro; }
	};
}