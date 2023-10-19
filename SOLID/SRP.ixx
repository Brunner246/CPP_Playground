//
// Created by michael.brunner on 19/10/2023.
//


module;

export module SRP;

import <string>;

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

	export class Document : public IJsonExportable, public ISerializable
	{
	public:
		Document() = default;

		~Document() override = default;

		[[nodiscard]] std::string toJson(/*...*/) const override
		{
			return {R"({"name":"Document"})"};
		}

		void serialize(/*...*/) override
		{
			// ... serialize ...
		}
	};
}