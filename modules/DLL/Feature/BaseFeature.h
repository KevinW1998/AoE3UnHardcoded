#pragma once

namespace UHCDLL
{

	class BaseFeature
	{
	protected:
		BaseFeature() = default;

		virtual bool OnActivate() { return true; }
		virtual bool OnReload() { return true; }


		virtual const char* GetName() { return ""; }
	};

}