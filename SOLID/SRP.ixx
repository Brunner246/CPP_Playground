//
// Created by michael.brunner on 19/10/2023.
//

module;

export module SRP;

import <string>;
import <utility>;
import <vector>;
import <fstream>;

namespace SOLID {
	class IJsonExportable
	{
	public:
		virtual ~IJsonExportable() noexcept = default;

		[[nodiscard]] virtual std::string toJson(/*...*/) const = 0;
	};

	class ISerializable
	{
	public:
		virtual ~ISerializable() noexcept = default;

		virtual void serialize(/*...*/) = 0;
	};

	export class JsonDocument : public IJsonExportable
	{
	public:
		JsonDocument() = default;

		~JsonDocument() override = default;

		[[nodiscard]] std::string toJson(/*...*/) const override
		{
			return {R"({"name":"JsonDocument"})"};
		}
	};

	export class SerializableDocument : public ISerializable
	{
	public:
		SerializableDocument() = default;

		~SerializableDocument() override = default;

		void serialize(/*...*/) override
		{
			// ... serialize ...
		}
	};

	export class Journal
	{
		std::string m_title;
		std::vector <std::string> m_entries;

	public:
		explicit Journal(std::string title)
				: m_title{std::move(title)}
		{
		}

		void add_entries(const std::string &entry)
		{
			static uint32_t count = 1;
			m_entries.push_back(std::to_string(count++) + ": " + entry);
		}

		[[nodiscard]] auto get_entries() const
		{
			return m_entries;
		}
	};

	export struct SavingManager
	{
		static void save(const Journal &j, const std::string &filename)
		{
			std::ofstream ofs(filename);
			for (auto &s: j.get_entries())
				ofs << s << std::endl;
		}
	};
}