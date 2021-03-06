/*************************************************************************
> File Name: Cards.cpp
> Project Name: Hearthstone++
> Author: Chan-Ho Chris Ohk
> Purpose: Cards class that stores a list of cards.
> Created Time: 2017/10/10
> Copyright (c) 2017, Chan-Ho Chris Ohk
*************************************************************************/
#include <Loaders/CardLoader.h>
#include <Models/Cards.h>

namespace Hearthstonepp
{
	Cards* Cards::m_instance = nullptr;

	Cards::Cards()
	{
		CardLoader loader;
		m_cards = loader.Load();
	}

	Cards::~Cards()
	{
		for (auto card : m_cards)
		{
			if (card != nullptr)
			{
				delete card;
			}
		}

		m_cards.clear();
	}

	Cards* Cards::GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new Cards();
		}

		return m_instance;
	}

	std::vector<Card*> Cards::GetAllCards() const
	{
		return m_cards;
	}

	const Card* Cards::FindCardByID(const std::string id)
	{
		for (auto card : m_cards)
		{
			if (card->GetID() == id)
			{
				return card;
			}
		}

		return nullptr;
	}

	std::vector<Card*> Cards::FindCardByRarity(Rarity rarity)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			if (card->GetRarity() == rarity)
			{
				result.emplace_back(card);
			}
		}

		return result;
	}

	std::vector<Card*> Cards::FindCardByClass(CardClass cardClass)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			if (card->GetCardClass() == cardClass)
			{
				result.emplace_back(card);
			}
		}

		return result;
	}

	std::vector<Card*> Cards::FindCardByType(CardType cardType)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			if (card->GetCardType() == cardType)
			{
				result.emplace_back(card);
			}
		}

		return result;
	}

	std::vector<Card*> Cards::FindCardByRace(Race race)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			if (card->GetRace() == race)
			{
				result.emplace_back(card);
			}
		}

		return result;
	}

	std::vector<Card*> Cards::FindCardByName(const std::string name)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			if (card->GetName().find(name) != std::string::npos)
			{
				result.emplace_back(card);
			}
		}

		return result;
	}

	std::vector<Card*> Cards::FindCardByCost(int minVal, int maxVal)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			if (card->GetCost() >= minVal && card->GetCost() <= maxVal)
			{
				result.emplace_back(card);
			}
		}

		return result;
	}

	std::vector<Card*> Cards::FindCardByAttack(int minVal, int maxVal)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			if (card->GetAttack() >= minVal && card->GetAttack() <= maxVal)
			{
				result.emplace_back(card);
			}
		}

		return result;
	}

	std::vector<Card*> Cards::FindCardByHealth(int minVal, int maxVal)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			if (card->GetHealth() >= minVal && card->GetHealth() <= maxVal)
			{
				result.emplace_back(card);
			}
		}

		return result;
	}

	std::vector<Card*> Cards::FindCardByMechanics(std::vector<GameTag> mechanics)
	{
		std::vector<Card*> result;

		for (auto card : m_cards)
		{
			auto mechanicsInCard = card->GetMechanics();

			for (auto mechanic : mechanics)
			{
				if (std::find(mechanicsInCard.begin(), mechanicsInCard.end(), mechanic) != mechanicsInCard.end())
				{
					result.emplace_back(card);
				}
			}
		}
		
		return result;
	}
}