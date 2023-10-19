//
// Created by michael.brunner on 19/10/2023.
//


module;

#include <memory>
#include <iostream>
#include <utility>

export module OCP;

import <vector>;
import <algorithm>;
import <ranges>;

namespace SOLID
{
	class ISharedData
	{
	public:
		virtual ~ISharedData() noexcept = default;

		virtual void Open() = 0;

		// Methods to access and modify the shared data.
	};

	class SharedData : public ISharedData
	{
	public:
		SharedData() = default;

		~SharedData() noexcept override = default;

		void Open() override
		{
			std::cout << "SharedData::Open()" << std::endl;
		}
	};

	class Document
	{
	public:
		explicit Document(std::shared_ptr<ISharedData> sharedData)
				: mSharedData(std::move(sharedData))
		{
		}

		virtual ~Document() noexcept = default;

		virtual void Open() = 0;
		virtual void Save() = 0;
		virtual void Close() = 0;

	protected:
		std::shared_ptr<ISharedData> mSharedData;
	};

	class PDFDocument : public Document
	{
	public:
		explicit PDFDocument(std::shared_ptr<ISharedData> sharedData)
				: Document(std::move(sharedData))
		{
		}

		~PDFDocument() noexcept override = default;

		void Open() override
		{
			// Open the PDF document using the shared data.
			mSharedData->Open();
		}

		void Save() override
		{
			// Save the PDF document using the shared data.
		}

		void Close() override
		{
			// Close the PDF document using the shared data.
		}
	};

	class WordDocument : public Document
	{
	public:
		explicit WordDocument(std::shared_ptr<ISharedData> sharedData)
				: Document(std::move(sharedData))
		{
		}

		~WordDocument() noexcept override = default;

		void Open() override
		{
			// Open the Word document using the shared data.
			mSharedData->Open();
		}

		void Save() override
		{
			// Save the Word document using the shared data.
		}

		void Close() override
		{
			// Close the Word document using the shared data.
		}
	};

	class JSONDocument : public Document
	{
	public:
		explicit JSONDocument(std::shared_ptr<ISharedData> sharedData)
				: Document(std::move(sharedData))
		{
		}

		~JSONDocument() noexcept override = default;

		void Open() override
		{
			// Open the JSON document using the shared data.
			mSharedData->Open();
		}

		void Save() override
		{
			// Save the JSON document using the shared data.
		}

		void Close() override
		{
			// Close the JSON document using the shared data.
		}
	};

	export void testFunction()
	{
		std::shared_ptr<ISharedData> sharedData = std::make_shared<SharedData>();


		std::vector<std::unique_ptr<Document>> documents{};

		documents.emplace_back(std::make_unique<PDFDocument>(sharedData));
		documents.emplace_back(std::make_unique<WordDocument>(sharedData));

		std::ranges::for_each(documents, [](auto &document) {
			document->Open();
			document->Save();
			document->Close();
		});
	}

}