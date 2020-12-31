#pragma once
#include "winxxdef.h"

namespace WrappedFunctions
{
	// Base Wrapping Classes

	// TODO: add utility functions for CHANDLE
	class CHANDLE
	{
	public:
		CHANDLE() = delete;

		explicit CHANDLE(HANDLE& _hHandle)
			: m_handle(_hHandle)
		{
			if (!m_handle) CHANDLE::~CHANDLE();
		}

		//
		//
		//
		//

        ~CHANDLE()
        {
			if (m_handle)
				CloseHandle(m_handle);
        }

		//
		//
		//
		//

		CHANDLE(const CHANDLE& other) = delete;

		CHANDLE(CHANDLE&& other) noexcept = delete;

		CHANDLE& operator=(const CHANDLE& other) = delete;

		CHANDLE& operator=(CHANDLE&& other) noexcept = delete;

		//
//
//
//

	protected:
		virtual HANDLE Get() noexcept
		{
			return m_handle;
		}

		bool ChangeHandle(const HANDLE& newHandle)
		{
			if (newHandle)
			{
				m_handle = newHandle;
				CloseHandle(newHandle);
				return true;
			}
			else
			{
				return false;
			}
		}

	protected:
		HANDLE m_handle;
	};

	class CHWND
	{
	public:
		CHWND() = delete;

		//
		//
		//
		//

		explicit CHWND(HWND hWnd)
			: m_hwnd(hWnd)
		{
			if (!m_hwnd) CHWND::~CHWND();
		}

		~CHWND() noexcept
		{
			if (m_hwnd)
				DestroyWindow(m_hwnd);
		}

		//
		//
		//
		//

		CHWND(const CHWND& other) = delete;

		CHWND(CHWND&& other) noexcept = delete;

		CHWND& operator=(const CHWND& other) = delete;

		CHWND& operator=(CHWND&& other) noexcept = delete;

		//
		//
		//
		//

	protected:
		HWND Get() noexcept
		{
			return m_hwnd;
		}

		//
		//
		//
		//

		bool ChangeHandle(const HWND& newHandle)
		{
			if (newHandle)
			{
				m_hwnd = newHandle;
				CloseHandle(newHandle);
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		HWND m_hwnd;

	};
}