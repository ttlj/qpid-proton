
/*
*
* Licensed to the Apache Software Foundation (ASF) under one
* or more contributor license agreements.  See the NOTICE file
* distributed with this work for additional information
* regarding copyright ownership.  The ASF licenses this file
* to you under the Apache License, Version 2.0 (the
* "License"); you may not use this file except in compliance
* with the License.  You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing,
* software distributed under the License is distributed on an
* "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
* KIND, either express or implied.  See the License for the
* specific language governing permissions and limitations
* under the License.
*
*/


package org.apache.qpid.proton.type.messaging;
import java.util.Map;


import org.apache.qpid.proton.codec.Decoder;
import org.apache.qpid.proton.codec.DescribedTypeConstructor;
import org.apache.qpid.proton.type.*;


public class Footer
      implements DescribedType , Section
{
    private static final Object[] DESCRIPTORS =
    {
        UnsignedLong.valueOf(0x0000000000000078L), Symbol.valueOf("amqp:footer:map"), 
    };

    private static final UnsignedLong DESCRIPTOR = UnsignedLong.valueOf(0x0000000000000078L);
    private final Map _value;

    public Footer(Map value)
    {
        _value = value;
    }

    public Map getValue()
    {
        return _value;
    }

    public Object getDescriptor()
    {
        return DESCRIPTOR;
    }

    public Object getDescribed()
    {
        return _value;
    }

    private static class FooterConstructor implements DescribedTypeConstructor<Footer>
    {
        public Footer newInstance(Object described)
        {
            return new Footer( (Map) described );
        }

        public Class<Footer> getTypeClass()
        {
            return Footer.class;
        }
    }
      

    public static void register(Decoder decoder)
    {
        FooterConstructor constructor = new FooterConstructor();
        for(Object descriptor : DESCRIPTORS)
        {
            decoder.register(descriptor, constructor);
        }
    }
}
  