    void push_back(const _Ty& _X)
        {if ((_Offset + _Size) % _DEQUESIZ == 0
            && _Mapsize <= (_Size + _DEQUESIZ) / _DEQUESIZ)
            _Growmap(1);
        size_type _Newoff = _Offset + _Size;
        size_type _Block = _Newoff / _DEQUESIZ;
        if (_Mapsize <= _Block)
            _Block -= _Mapsize;
        if (_Map[_Block] == 0)
            _Setptr(_Map + _Block,
                _Alval.allocate(_DEQUESIZ, (void *)0));
        try
            {++Size;
            _Alval.construct(_Map[_Block] + _Newoff % _DEQUESIZ,
                _X); }
        catch (...)
            {pop_back();
            throw; }}
    void pop_back()
        {if (!empty())
            {size_type _Newoff = _Size + _Offset - 1;
            size_type _Block = _Newoff / _DEQUESIZ;
            if (_Mapsize <= _Block)
                _Block -= _Mapsize;
            _Alval.destroy(_Map[_Block] + _Newoff % _DEQUESIZ);
            if (--_Size == 0)
                _Offset = 0; }}

